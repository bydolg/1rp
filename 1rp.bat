IF EXIST "d:\SteamLibrary\steamapps\common\Arma 3 Server\mpmissions\update\1rp.Altis.pbo" move /Y "d:\SteamLibrary\steamapps\common\Arma 3 Server\mpmissions\update\1rp.Altis.pbo" "d:\SteamLibrary\steamapps\common\Arma 3 Server\mpmissions\1rp.Altis.pbo" 
rem move /Y "C:\Update\Server_addons\*.*" "c:\Arma3\@ExileServer\addons\"
rem move /Y "C:\Update\OneRP_addons\*.*" "c:\Arma3\@OneRP\addons\"
rem move /Y "c:\Update\Exile_addons\*.*" "c:\Arma3\@EXILE\addons\"
rem IF EXIST "C:\Update\a3_infiSTAR_Exile.pbo" move /Y "C:\Update\a3_infiSTAR_Exile.pbo" "c:\Arma3\@ExileServer\addons\a3_infiSTAR_Exile.pbo"
rem del /Q /F "d:\Games\SteamLibrary\steamapps\common\Arma 3 Server\1rp_config\*.mdmp"
rem del /Q /F "d:\Games\SteamLibrary\steamapps\common\Arma 3 Server\1rp_config\*.bidmp"
rem timeout 10


cd "d:\SteamLibrary\steamapps\common\Arma 3 Server"
start arma3server_x64.exe -malloc=tbb4malloc_bi_x64 "-config=1rp_config\config.cfg" "-profiles=1rp_config\profiles" "-cfg=1rp_config\basic.cfg" "-servermod=@extDB3;@life_server" "-mod=@belas" -port=2314 -hugepages -cpuCount=3 -exThreads=1 -autoInit

timeout 60
start servermonitor.bat
timeout 90
start bec.bat
exit
