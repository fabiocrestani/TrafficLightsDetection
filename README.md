# Traffic Lights Detection and Recognition
Traffic Lights Detection and Recoginition with Computer Vision and Embedded Systems

Driver assistance systems are becoming an ubiquitous technology in the past few years. With these systems comes the necessity to develop a reliable traffic lights recognition system. In this paper we present an implementation of such system using solely computer vision. Our algorithm recognize, classifies and tracks circular traffic headlights in images obtained from a camera feed without any other additional sensors input. The proposed tracking system takes advantage of the assumption that once a semaphore is detected, it is very likely to be detected again in following frames. Therefore, it is possible to save computational power, increase the confidence of some results and decrease the number of false positives. **The results indicated an overall accuracy of 71% with almost 2% of false positives on a sequence of images of 1789 frames.**

![Block diagram](https://raw.githubusercontent.com/fabiocrestani/TrafficLightsDetection/master/docs/figures/figure1.png)

![](https://raw.githubusercontent.com/fabiocrestani/TrafficLightsDetection/master/docs/figures/figure2.png)
