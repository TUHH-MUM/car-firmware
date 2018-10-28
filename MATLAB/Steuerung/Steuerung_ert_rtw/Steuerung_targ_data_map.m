  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Steuerung_P)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Steuerung_P.DiscretePIDController_D
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Steuerung_P.DiscretePIDController_P
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Steuerung_P.SliderGain_gain
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Steuerung_P.SliderGain1_gain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Steuerung_P.FindLocalMaxima_threshold
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Steuerung_P.DrawShapes_lineWidth
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Steuerung_P.EdgeDetection_thresholdTuning
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 22;
      section.data(22)  = dumData; %prealloc
      
	  ;% Steuerung_P.Constant7_Value
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Steuerung_P.Constant6_Value
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Steuerung_P.Constant2_Value
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Steuerung_P.Constant_Value
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Steuerung_P.K1_Gain
	  section.data(5).logicalSrcIdx = 11;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Steuerung_P.Normalization_Gain
	  section.data(6).logicalSrcIdx = 12;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Steuerung_P.Saturation_UpperSat
	  section.data(7).logicalSrcIdx = 13;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Steuerung_P.Saturation_LowerSat
	  section.data(8).logicalSrcIdx = 14;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Steuerung_P.Normalization1_Gain
	  section.data(9).logicalSrcIdx = 15;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Steuerung_P.Constant1_Value
	  section.data(10).logicalSrcIdx = 16;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Steuerung_P.Constant8_Value
	  section.data(11).logicalSrcIdx = 17;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Steuerung_P.Normalization_Gain_l
	  section.data(12).logicalSrcIdx = 18;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Steuerung_P.Gain_Gain
	  section.data(13).logicalSrcIdx = 19;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Steuerung_P.Constant5_Value
	  section.data(14).logicalSrcIdx = 20;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Steuerung_P.Gain3_Gain
	  section.data(15).logicalSrcIdx = 21;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Steuerung_P.Gain2_Gain
	  section.data(16).logicalSrcIdx = 22;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Steuerung_P.theta_d_Value
	  section.data(17).logicalSrcIdx = 23;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Steuerung_P.y_d_Value
	  section.data(18).logicalSrcIdx = 24;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Steuerung_P.TSamp_WtEt
	  section.data(19).logicalSrcIdx = 25;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Steuerung_P.UD_InitialCondition
	  section.data(20).logicalSrcIdx = 26;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Steuerung_P.Gain1_Gain
	  section.data(21).logicalSrcIdx = 27;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Steuerung_P.Constant3_Value
	  section.data(22).logicalSrcIdx = 28;
	  section.data(22).dtTransOffset = 21;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Steuerung_P.UD_DelayLength
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Steuerung_P.ManualSwitch1_CurrentSetting
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Steuerung_P.ManualSwitch_CurrentSetting
	  section.data(2).logicalSrcIdx = 31;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Steuerung_P.ManualAutomaticSteering_Current
	  section.data(3).logicalSrcIdx = 32;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Steuerung_P.DrawShapes_RTP_FILLCOLOR
	  section.data(4).logicalSrcIdx = 33;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 9;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Steuerung_B)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Steuerung_B.HoughTransform_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Steuerung_B.HoughTransform_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 36180;
	
	  ;% Steuerung_B.HoughTransform_o3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 36360;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Steuerung_B.HoughLines
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Steuerung_B.V4L2VideoCapture_o1
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Steuerung_B.V4L2VideoCapture_o2
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Steuerung_B.V4L2VideoCapture_o3
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 38400;
	
	  ;% Steuerung_B.Image_Lines_1
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 76800;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Steuerung_B.steeringangle
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Steuerung_B.DataTypeConversion1
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Steuerung_B.DataTypeConversion3
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Steuerung_B.MCU6050_o1
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Steuerung_B.MCU6050_o2
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Steuerung_B.MCU6050_o3
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Steuerung_B.MCU6050_o4
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Steuerung_B.MCU6050_o5
	  section.data(5).logicalSrcIdx = 11;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Steuerung_B.MCU6050_o6
	  section.data(6).logicalSrcIdx = 12;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Steuerung_B.MCU6050_o7
	  section.data(7).logicalSrcIdx = 13;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Steuerung_B.PCF8591
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Steuerung_B.LogicalOperator2
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Steuerung_B.LogicalOperator1
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Steuerung_B.Imageedge
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 9;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Steuerung_DW)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Steuerung_DW.UD_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Steuerung_DW.PCA6585_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Steuerung_DW.PCF8591_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Steuerung_DW.MCU6050_DSTATE
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Steuerung_DW.FindLocalMaxima_TEMP_IN_DWORKS
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Steuerung_DW.Scope3_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Steuerung_DW.Scope_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Steuerung_DW.Scope1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 5;
	
	  ;% Steuerung_DW.Scope2_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% Steuerung_DW.EdgeDetection_VO_DW
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Steuerung_DW.EdgeDetection_HO_DW
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 6;
	
	  ;% Steuerung_DW.EdgeDetection_VOU_DW
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 12;
	
	  ;% Steuerung_DW.EdgeDetection_VOD_DW
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 18;
	
	  ;% Steuerung_DW.EdgeDetection_VOL_DW
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 24;
	
	  ;% Steuerung_DW.EdgeDetection_VOR_DW
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 30;
	
	  ;% Steuerung_DW.EdgeDetection_HOU_DW
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 36;
	
	  ;% Steuerung_DW.EdgeDetection_HOD_DW
	  section.data(8).logicalSrcIdx = 16;
	  section.data(8).dtTransOffset = 42;
	
	  ;% Steuerung_DW.EdgeDetection_HOL_DW
	  section.data(9).logicalSrcIdx = 17;
	  section.data(9).dtTransOffset = 48;
	
	  ;% Steuerung_DW.EdgeDetection_HOR_DW
	  section.data(10).logicalSrcIdx = 18;
	  section.data(10).dtTransOffset = 54;
	
	  ;% Steuerung_DW.EdgeDetection_VOUL_DW
	  section.data(11).logicalSrcIdx = 19;
	  section.data(11).dtTransOffset = 60;
	
	  ;% Steuerung_DW.EdgeDetection_VOLL_DW
	  section.data(12).logicalSrcIdx = 20;
	  section.data(12).dtTransOffset = 66;
	
	  ;% Steuerung_DW.EdgeDetection_VOUR_DW
	  section.data(13).logicalSrcIdx = 21;
	  section.data(13).dtTransOffset = 72;
	
	  ;% Steuerung_DW.EdgeDetection_VOLR_DW
	  section.data(14).logicalSrcIdx = 22;
	  section.data(14).dtTransOffset = 78;
	
	  ;% Steuerung_DW.EdgeDetection_HOUL_DW
	  section.data(15).logicalSrcIdx = 23;
	  section.data(15).dtTransOffset = 84;
	
	  ;% Steuerung_DW.EdgeDetection_HOLL_DW
	  section.data(16).logicalSrcIdx = 24;
	  section.data(16).dtTransOffset = 90;
	
	  ;% Steuerung_DW.EdgeDetection_HOUR_DW
	  section.data(17).logicalSrcIdx = 25;
	  section.data(17).dtTransOffset = 96;
	
	  ;% Steuerung_DW.EdgeDetection_HOLR_DW
	  section.data(18).logicalSrcIdx = 26;
	  section.data(18).dtTransOffset = 102;
	
	  ;% Steuerung_DW.FindLocalMaxima_DIMS1
	  section.data(19).logicalSrcIdx = 27;
	  section.data(19).dtTransOffset = 108;
	
	  ;% Steuerung_DW.Selector2_DIMS1
	  section.data(20).logicalSrcIdx = 28;
	  section.data(20).dtTransOffset = 110;
	
	  ;% Steuerung_DW.Selector_DIMS1
	  section.data(21).logicalSrcIdx = 29;
	  section.data(21).dtTransOffset = 112;
	
	  ;% Steuerung_DW.Selector1_DIMS1
	  section.data(22).logicalSrcIdx = 30;
	  section.data(22).dtTransOffset = 113;
	
	  ;% Steuerung_DW.Selector3_DIMS1
	  section.data(23).logicalSrcIdx = 31;
	  section.data(23).dtTransOffset = 115;
	
	  ;% Steuerung_DW.HoughLines_DIMS1
	  section.data(24).logicalSrcIdx = 32;
	  section.data(24).dtTransOffset = 116;
	
	  ;% Steuerung_DW.EdgeDetection_MEAN_FACTOR_DW
	  section.data(25).logicalSrcIdx = 34;
	  section.data(25).dtTransOffset = 118;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2511292437;
  targMap.checksum1 = 563146016;
  targMap.checksum2 = 595279931;
  targMap.checksum3 = 3472454600;

