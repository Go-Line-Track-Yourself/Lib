void GyroTest(){
    Gyro.startCalibration();
    while(1){
        Brain.Screen.ClearLine();
        Brain.Screen.print(Gyro.value(vex::rotationUnits::deg));
        vex::task::sleep(20);
    }
}

void Code(){
    Brain.Screen.render(true,false);
    GyroTest();
}