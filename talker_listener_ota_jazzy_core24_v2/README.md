# ROSCon Toronto OTA demo

Build and install the ROS 2 Jazzy snap:

```bash
# switch to v1
snapcraft pack
sudo snap install ./roscon-toronto-ota-demo_1.0.0_amd64.snap --dangerous
```

The talker starts as a service. Run the listener in a terminal:

```bash
roscon-toronto-ota-demo.listener
```

Build revision 2 from its branch:

```bash
# switch to v2
snapcraft clean roscon-ota-demo
snapcraft pack
sudo snap install ./roscon-toronto-ota-demo_2.0.0_amd64.snap --dangerous
```
