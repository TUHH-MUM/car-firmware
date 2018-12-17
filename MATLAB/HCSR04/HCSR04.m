classdef HCSR04 < matlab.System ...
        & coder.ExternalDependency ...
        & matlab.system.mixin.CustomIcon
        
    properties
      % Public, tunable properties.
    end
    properties (Nontunable)
      % Public, non-tunable properties.
    end
    properties (Access = private)
      % Pre-computed constants.
    end
    methods
      % Constructor
        function obj = HCSR04(varargin)
            coder.allowpcode('plain')
              % Support name-value pair arguments when constructing the object.
            setProperties(obj,nargin,varargin{:});
        end
    end
    methods (Access=protected)
        function setupImpl(obj)
        end
        function distance_cm = stepImpl(obj)
            out = double(zeros(1,1));
            if isempty(coder.target)
              % Place simulation output code here 
            else
              % Call C-function implementing device output
                coder.cinclude('HCSR04.h');
                out = coder.ceval('read_value');
            end
            distance_cm = out(1);
        end
        function releaseImpl(obj)
            if isempty(coder.target)
              % Place simulation termination code here
            else
              % Call C-function implementing device termination
            end
        end
    end
    methods (Access=protected)
          % Define input properties
        function icon = getIconImpl(~)
            icon = 'HC-SR04';
        end
    end
    methods (Static, Access=protected)
        function simMode = getSimulateUsingImpl(~)
            simMode = 'Interpreted execution';
        end
        function isVisible = showSimulateUsingImpl
            isVisible = false;
        end
    end
    methods (Static)
        function name = getDescriptiveName()
            name = 'HCSR04';
        end
        function b = isSupportedContext(context)
            b = context.isCodeGenTarget('rtw');
        end
        function updateBuildInfo(buildInfo, context)
            if context.isCodeGenTarget('rtw')
                  % Update buildInfo
                srcDir = fullfile(fileparts(mfilename('fullpath')),'src');
                includeDir = fullfile(fileparts(mfilename('fullpath')),'include');
                addIncludePaths(buildInfo,includeDir);    
                addSourceFiles(buildInfo,'HCSR04.c',srcDir);        
            end
        end
    end
end