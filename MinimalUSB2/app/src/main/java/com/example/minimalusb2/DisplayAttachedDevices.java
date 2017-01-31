package com.example.minimalusb2;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.ViewGroup;
import android.widget.TextView;

public class DisplayAttachedDevices extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_display_attached_devices);

        Intent intent = getIntent();
        String result = intent.getStringExtra(MainActivity.EXTRA_SEARCH_RESULT);

        // Get the layout
        ViewGroup layout = (ViewGroup) findViewById(R.id.activity_display_attached_devices);

        // Devices found boolean
        TextView tvResult = new TextView(this);
        tvResult.setTextSize(30);
        tvResult.setText("Devices found: " + result);
        layout.addView(tvResult);
    }
}
