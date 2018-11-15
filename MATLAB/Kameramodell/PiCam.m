%% Skript zum Aufnehmen von Bildern mit der Raspberry Pi Kamera
%
%
%
% Autor: Lukas Cherouny, Svenja Otto
%
%
% Datum: 15.11.18
%


%% -------------------------------- init ---------------------------------
clear 
close all
clc

%% -----------------------------------------------------------------------
% Verbindung mit dem PI wird hergestellt
picar = raspi('192.168.4.1', 'pi', 'raspberry');%ip, nutzer, passwort

msg1 = strcat('connected to pi with IP Adress',{' '},picar.DeviceAddress);
disp(msg1{1})

% Verbindung zum Kameraboard
% !! Achtung : Auflösung anpassen !! 
cam = cameraboard(picar, 'Resolution', '1280x720');
% preview(cam)

% Warten auf Nutzerrückmeldnug
x = input('Press enter to start taking 20 images');

% ------------------------- Aufnehmen der Fotos --------------------------
i = 1; 
maximages = 20;
data = cell(maximages,1);
while i <= maximages
    
%     input('Press Enter for next image');
    
    % Foto machen
    data{i} = snapshot(cam);
    % Speichere Bild in den Ordner Pics
    imwrite(data{i}, sprintf('Pics2/Pic%03d.jpg',i))
    % Zeige Bild an
    figure('Position',[1e3 5e2 5e2 8e2])
    imshow(data{i});

    % Nutzernachricht
    info = strcat('image',{' '},num2str(i),{' '},'of',{' '},num2str(maximages),{' '},'taken');
    disp(info{1})
    
    i=i+1;
    
    pause(1);
    disp('4 s')
        
    pause(1);
    disp('3 s')
        
    pause(1);
    disp('2 s')
    
    pause(1);
    disp('1 s')
end

% end 
