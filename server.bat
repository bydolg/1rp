Start bec.bat

cd "d:\SteamLibrary\steamapps\common\Arma 3 Server"
IF EXIST "d:\SteamLibrary\steamapps\common\Arma 3 Server\mpmissions\update\1rp.Altis.pbo" move /Y "d:\SteamLibrary\steamapps\common\Arma 3 Server\mpmissions\update\1rp.Altis.pbo" "d:\SteamLibrary\steamapps\common\Arma 3 Server\mpmissions\1rp.Altis.pbo"
IF EXIST "d:\SteamLibrary\steamapps\common\Arma 3 Server\mpmissions\update\1rp.Bozcaada.pbo" move /Y "d:\SteamLibrary\steamapps\common\Arma 3 Server\mpmissions\update\1rp.Bozcaada.pbo" "d:\SteamLibrary\steamapps\common\Arma 3 Server\mpmissions\1rp.Bozcaada.pbo"

start arma3server_x64.exe -malloc=tbb4malloc_bi_x64 "-config=1rp_config\config.cfg" "-profiles=1rp_config\profiles" "-cfg=1rp_config\basic.cfg" "-servermod=@extDB3;@life_server" "-mod=@belas" -port=2314 -hugepages -cpuCount=3 -exThreads=1 -autoInit
Start servermonitor.bat
exit
