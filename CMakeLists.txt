cmake_minimum_required(VERSION 2.8)

################
# mudbox 
set (MUDBOXSDK_DIR "C:/Program Files/Autodesk/Mudbox 2014/SDK")
set (MUDBOXSDK_INC_DIR ${MUDBOXSDK_DIR}/include)
set (MUDBOXSDK_QT_INC_DIR
	${MUDBOXSDK_INC_DIR}/QtCore
	${MUDBOXSDK_INC_DIR}/QtGui
	${MUDBOXSDK_INC_DIR}/QtOpenGL
)
set (MUDBOXSDK_LIB_DIR ${MUDBOXSDK_DIR}/lib)
set (MUDBOXSDK_LIB 
	cg.lib
	cgGL.lib
	EdgeBleeding.lib
	MapExtractor.lib
	MapExtractorAPI.lib
	MudboxFramework.lib
	phonon4.lib	
	QtCore4.lib
	QtGui4.lib	
	QtNetwork4.lib	
	QtOpenGL4.lib
	QtScript4.lib
	QtSql4.lib
	QtSvg4.lib
	QtWebKit4.lib
	QtXml4.lib
	UVlessPainting.lib
)

include_directories ("${MUDBOXSDK_INC_DIR}" ${MUDBOXSDK_QT_INC_DIR})
link_directories (   "${MUDBOXSDK_LIB_DIR}") 	


################
# 
project (Mudbox_custom_plugin_LayerOps)

set (PLUGIN_NAME Mudbox_custom_plugin_LayerOps)

set(SRC 
	PluginMain.cpp	

	LayerCleaner.h
	LayerCleaner.cpp
	 
)

add_library(${PLUGIN_NAME} SHARED ${SRC})

target_link_libraries(
    ${PLUGIN_NAME}

	${MUDBOXSDK_LIB}
)
