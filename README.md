Mudbox_custom_plugin_CleanLayers
================================

To use the CMake to build a simple custom plugin of Mudbox

###How to build this plugin on Windows?

Step 1. Downlaod the source code, put it into a folder, 
for example G:/Mudbox_custom_plugin_CleanLayers, 
make sure that the CMakeLists.txt is at G:/Mudbox_custom_plugin_CleanLayers/CMakeLists.txt.

Step 2. Run cmake-gui, 
Fill the build folder with G:/Mudbox_custom_plugin_CleanLayers_vs_2010_x64, 
Choose VS 2010 win64 to configure and generate the vs project file.

Step 3. Build the project in VS. You get this plugin: 
Mudbox_custom_plugin_CleanLayers.dll 

Step 4. 
You can copy the Mudbox_custom_plugin_CleanLayers.dll into the 
C:\Program Files\Autodesk\Mudbox 2014\plugins
or 
You can set MUDBOX_PLUG_IN_PATH="some folder in your pc", and put that .dll into there.

Step 5. Run Mudbox.exe, you will find the menu "Mesh" -> "Remove all the sculpt layers".
That is it.

###

Let me know if you have further questions. Thank you very much.
canjiang.ren(you know this "at":-)gmail.com
