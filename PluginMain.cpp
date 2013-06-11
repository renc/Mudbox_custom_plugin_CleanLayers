#include <QtCore/QObject> // include this before mudbox headers.
#include <Mudbox/mudbox.h>  

#include "LayerCleaner.h"  

using namespace mudbox;

void Initializer();
void MenuItemHandler_RemoveLayers();

static const char *sPluginName = "CustomLayerOp";
static const char *sPluginDescription = "some custom layer operations";
static const char *sPluginAuthorName = "";
static const char *sPluginURL = "";
// Register this plugin. The "Initializer" method will be called when the plugin is loaded.
MB_PLUGIN( sPluginName, sPluginDescription, sPluginAuthorName, sPluginURL, Initializer );

// This function will be called then the plugin is loaded.
void Initializer(void)
{
	// Add a menu entry for this operation.																												 
	Kernel()->Interface()->AddCallbackMenuItem( mudbox::Interface::menuMesh, QString::null, QObject::tr("Remove all the sculpt layers"), MenuItemHandler_RemoveLayers);
}

void MenuItemHandler_RemoveLayers()
{
	CleanSculptLayers();
} 
