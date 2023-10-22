clear all;
clear a;

%arduino setting on matlab
a = arduino('COM11', 'Uno', 'Libraries', {'Ultrasonic', 'Servo'});
s = servo(a, 'D10');
u = ultrasonic(a,'D3', 'D4'); %3 trig, 4 echo

i = 0;
while true %loop
    i = i+1;
    distance = readDistance(u);

    %object closer  
    if distance <= 0.1
        writePosition(s,0.5); %open the food
        pause(2);
        writePosition(s,0); %close the food
        pause(2);
    end
end