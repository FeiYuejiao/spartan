## Camera calibration in Spartan

### Prepare to capture images

- Decide the device's serial number or name
- Create a new folder in `station_config/hand_eye_calibration` and create a new `.yaml` file.  Copy over the structure from another yaml file.
- Specify in `iiwamanipdev.py` what the name of this `.yaml` file is within `station_config`
- Create a new folder in `camera_config` and copy over the structure from other folders
- Rebuild catkin_project/fast
```
cd spartan/build
make catkin_projects/fast
```
- When you launch the sensor via `roslaunch camera_config openni2.launch`, pass the serial_number you chose

### Capture images

- Place the calibration target (place the pieces of tape with `*`s on them next to each other)

#### Capture RGB images

- Launch director
- `cal.run()` in the Python terminal (it's f8)
- (by default, the rgb images are captured)
- Open rviz, and look at the camera topic to make sure the target is in frame (at least in most images)
- Images will be saved to, for example:
```
spartan/calibration_data/20180201-233350_rgb/
```

#### Capture IR images

- Cover the projector
- Set up the IR illuminators
- View the IR images in rviz and make sure the IR illumination is good enough (it can be sensitive to the height and angle of the IR illuminator)
- `cal.run(captureRGB=False, captureIR=True)`


TODO
- add picture of IR illuminators setup
- later: clean up station_config structure (not just one cal.yaml)
- extrinsics should live in station_config
- adjust joint limits