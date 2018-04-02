echo @off
echo trying to work
ssh root@192.168.125.1
echo Connecting to wallaby...
cd parksiderepo/somas
echo Connected to Wallaby, building...
make
cd bin
echo Running program...
./botball_user_program
exit