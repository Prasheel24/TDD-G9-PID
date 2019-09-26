
## Class definition

PID.h
pidConroller method

Attributes-
Shared pointer types-
	Private : 
		vector<double> Kp(3);  --> P Gains
		vector<double> Ki(3);  --> I Gains
		vector<double> Kd(3);  --> D Gains
		vector<double> setPoint(3) -->
		vector<double> finalVelocity(3);  
		vector<double> actualVelocity(3);
		double errorSum;
		double lastVelocity;
		double maxLimitV;
		
		vector<double> maxLimitP;
		
			
	Public :
		changeGain(); --> input: shared pointer vector output: shared pointer vector
		computeOutput(); --> output new gain
	
		getActualVelocity();
		setActualVelocity();
		setMaxLimit()V;
		getMaxLimit()V;
		
		setMaxLimit()P;
		getMaxLimit()P;
		
		updateError();
		
		resetSystem(); --> refresh the inputs and system to reboot.

			
Test Cases:
		(default to zero and system stops except for error sum)
	setGain >=0 --> stability 
	setMaxLimitV --> value should be in double range 
	setPoint --> magnitude less than maxlimit
	compute --> magnitude less than max limit
	setActualVelocity --> Magnitude less than max limit
	errorSum --> check data type overflow> give a warning if near boundary
	
	 
	
