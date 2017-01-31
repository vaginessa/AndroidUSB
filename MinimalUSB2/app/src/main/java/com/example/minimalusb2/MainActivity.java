package com.example.minimalusb2;

import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.graphics.Color;
import android.hardware.usb.UsbDevice;
import android.hardware.usb.UsbDeviceConnection;
import android.hardware.usb.UsbEndpoint;
import android.hardware.usb.UsbInterface;
import android.hardware.usb.UsbManager;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.Layout;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

public class MainActivity extends AppCompatActivity {
    public final static String EXTRA_SEARCH_RESULT = "com.example.myfirstapp.SEARCH_RESULT";
    private static final String ACTION_USB_PERMISSION = "com.android.example.USB_PERMISSION";
    private static final String TAG = "MainActivity";
    PendingIntent mPermissionIntent;
    UsbManager manager;
    UsbDeviceConnection connection;

    // bmRequestType
    static final int bmRead = 0b10000000;
    static final int bmWrite = 0b00000000;
    // bRequest values
    static final int brLedToggle = 15;
    static final int brReadButtons = 17;
    // LED Toggle wValue values
    static final int wvRedOn = 1;
    static final int wvAmberOn = 2;
    static final int wvGreenOn = 3;
    static final int wvRedOff = 4;
    static final int wvAmberOff = 5;
    static final int wvGreenOff = 6;
    // LED Toggle States
    boolean GreenOn = false;
    boolean AmberOn = false;
    boolean RedOn = false;
    // Button state
    byte[] button_buffer = {0}; // Least significant three bits used; 1 = open, 0 = closed
    View viewSW1;
    View viewSW2;
    View viewSW3;
    // USB coms
    int TIMEOUT = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mPermissionIntent = PendingIntent.getBroadcast(this, 0, new Intent(ACTION_USB_PERMISSION), 0);
        IntentFilter filter = new IntentFilter(ACTION_USB_PERMISSION);
        registerReceiver(mUsbReceiver, filter);

        // Set the colors of the switch display panels
        viewSW1 = (View) findViewById(R.id.SW1);
        viewSW2 = (View) findViewById(R.id.SW2);
        viewSW3 = (View) findViewById(R.id.SW3);
        viewSW1.setBackgroundColor(Color.GRAY);
        viewSW2.setBackgroundColor(Color.GRAY);
        viewSW3.setBackgroundColor(Color.GRAY);

    }

    /** Called when the user clicks the search button */
    public void searchForUSBs(View view) {
        manager = (UsbManager) getSystemService(Context.USB_SERVICE);
        HashMap<String, UsbDevice> deviceList = manager.getDeviceList();
        Boolean noDevices = deviceList.isEmpty();

        TextView tvResult = (TextView) findViewById(R.id.recognised);

        UsbDevice device = null;
        Integer deviceProductID = 0;
        Integer deviceVendorID = 0;

        String path = "";
        if (noDevices == false) {
            Set<String> deviceNames = deviceList.keySet();
            Iterator<String> nameIterator = deviceNames.iterator();
            if (nameIterator.hasNext()) {
                path = nameIterator.next();
                device = deviceList.get(path);
                // deviceClass = device.getDeviceClass();
                deviceProductID = device.getProductId();
                deviceVendorID = device.getVendorId();
            }
        }

        //Intent intent = new Intent(this, DisplayAttachedDevices.class);
        //intent.putExtra(EXTRA_SEARCH_RESULT, ((Boolean)!noDevices).toString());

        //startActivity(intent);

        TextView tvConnected = (TextView) findViewById(R.id.connected);
        tvConnected.setText(" " + ((Boolean) !noDevices).toString());

        TextView tvPath = (TextView) findViewById(R.id.path);
        if (noDevices == false) {
            tvPath.setText(" " + path);
            // Check that the correct device is present
            if (deviceProductID == 1 && deviceVendorID == 0) {
                // Confirm that the device has been recognised
                tvResult.setTextColor(Color.GREEN);
                tvResult.setText("Device recognised");
                // Configure communication
                manager.requestPermission(device, mPermissionIntent);
                    // Create test buttons
                    //Button send_ct = new Button(this);
                    //send_ct.setText("@string/sendCT");
                    //ViewGroup layout = (ViewGroup) findViewById(R.id.activity_main);
                    //layout.addView(send_ct);
            } else {
                // Device has not been recognised;
                tvResult.setTextColor(Color.RED);
                tvResult.setText("Device not recognised");
            }
        } else {
            tvPath.setText(" none");
            tvResult.setText("");
        }
    }

    private final BroadcastReceiver mUsbReceiver = new BroadcastReceiver() {
        public void onReceive(Context context, Intent intent) {
            String action = intent.getAction();
            if (ACTION_USB_PERMISSION.equals(action)) {
                synchronized (this) {
                    UsbDevice device = (UsbDevice)intent.getParcelableExtra(UsbManager.EXTRA_DEVICE);

                    if (intent.getBooleanExtra(UsbManager.EXTRA_PERMISSION_GRANTED, false)) {
                        if(device != null){
                            //call method to set up device communication
                            boolean forceClaim = true;
                            UsbInterface intf = device.getInterface(0);
                            UsbEndpoint endpoint = intf.getEndpoint(0);
                            connection = manager.openDevice(device);
                            connection.claimInterface(intf, forceClaim);
                            //  Make test buttons visible
                            Button green = (Button) findViewById(R.id.green);
                            green.setVisibility(View.VISIBLE);
                            Button amber = (Button) findViewById(R.id.amber);
                            amber.setVisibility(View.VISIBLE);
                            Button red = (Button) findViewById(R.id.red);
                            red.setVisibility(View.VISIBLE);
                            // Make button views visible
                            viewSW1.setVisibility(View.VISIBLE);
                            viewSW2.setVisibility(View.VISIBLE);
                            viewSW3.setVisibility(View.VISIBLE);
                            // Create a new thread to read button state
                            new Thread(new Runnable() {
                                @Override
                                public void run(){
                                    while(true){
                                        connection.controlTransfer(bmRead,
                                                brReadButtons,
                                                0, 0,
                                                button_buffer,
                                                1, TIMEOUT);
                                        viewSW1.post(new Runnable() {
                                            @Override
                                            public void run() {
                                                // Remember that the button buffer bits are
                                                // normally 1; 0 if the button is pressed
                                                if((button_buffer[0] & 0b0001) == 0b0001){
                                                    viewSW3.setBackgroundColor(Color.GRAY);
                                                } else {
                                                    viewSW3.setBackgroundColor(Color.GREEN);
                                                }
                                                if((button_buffer[0] & 0b0010) == 0b0010){
                                                    viewSW2.setBackgroundColor(Color.GRAY);
                                                } else {
                                                    viewSW2.setBackgroundColor(Color.GREEN);
                                                }
                                                if((button_buffer[0] & 0b0100) == 0b0100){
                                                    viewSW1.setBackgroundColor(Color.GRAY);
                                                } else {
                                                    viewSW1.setBackgroundColor(Color.GREEN);
                                                }
                                            }
                                        });
                                    }
                                }
                            }).start();
                        }
                    }
                    else {
                        Log.d(TAG, "permission denied for device " + device);
                    }
                }
            }
        }
    };

    /** Called when user clicks Green */
    public void toggleGreen(View view){
        if(GreenOn == false) {
            connection.controlTransfer(bmWrite, brLedToggle, wvGreenOn, 0, null, 0, TIMEOUT);
            GreenOn = true;
        } else {
            connection.controlTransfer(bmWrite, brLedToggle, wvGreenOff, 0, null, 0, TIMEOUT);
            GreenOn = false;
        }
    }

    /** Called when user clicks Amber */
    public void toggleAmber(View view){
        int TIMEOUT = 0;
        if(AmberOn == false) {
            connection.controlTransfer(bmWrite, brLedToggle, wvAmberOn, 0, null, 0, TIMEOUT);
            AmberOn = true;
        } else {
            connection.controlTransfer(bmWrite, brLedToggle, wvAmberOff, 0, null, 0, TIMEOUT);
            AmberOn = false;
        }
    }

    /** Called when user clicks Red */
    public void toggleRed(View view){
        int TIMEOUT = 0;
        if(RedOn == false) {
            connection.controlTransfer(bmWrite, brLedToggle, wvRedOn, 0, null, 0, TIMEOUT);
            RedOn = true;
        } else {
            connection.controlTransfer(bmWrite, brLedToggle, wvRedOff, 0, null, 0, TIMEOUT);
            RedOn = false;
        }
    }

    /** Called when the user clicks the OpenGL button */
    public void displayOpenGL(View view){

    }
}
