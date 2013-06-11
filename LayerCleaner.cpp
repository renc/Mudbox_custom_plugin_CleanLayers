#include <QtCore/QObject> // include this before mudbox headers.
#include <Mudbox/mudbox.h>  
#include "LayerCleaner.h"

using namespace mudbox;

void CleanSculptLayers()
{
	// traver all the geometries.
	for (unsigned int iG = 0; iG < Kernel()->Scene()->GeometryCount(); ++iG)
	{
		Geometry *pG = Kernel()->Scene()->Geometry(iG);
		if (!pG)
			continue;
		
		Store<Mesh *> aMeshes; 
		Store<LayerMeshData *> aLayers;

		// go through all the sculpt layers of this geometry,
		// they may lock to different levels though. 
		const unsigned int iLayerCount = pG->LayerCount();
		for (unsigned int iL = 0; iL < iLayerCount; ++iL)
		{
			LayerMeshData *pLayer = pG->LayerData(iL); 
			if (!pLayer)
				continue;

			Mesh *pMesh = pLayer->Mesh(); pMesh; 
			aMeshes.Add(pLayer->Mesh());
			aLayers.Add(pLayer);			 
		} 						   
		
		SubdivisionLevel *pActiveLevel = pG->ActiveLevel();
		for (unsigned int i = 0; i < aLayers.ItemCount(); ++i)
		{
			if (!aMeshes[i])
				continue;

			// sculpt layer can only be removed from the active level 
			// and this active level is the layer locked to.
			pG->ChangeActiveLevel(dynamic_cast<SubdivisionLevel *>(aMeshes[i]));
			aMeshes[i]->RemoveLayer(aLayers[i]);
			
			// update the mesh renderer.
			aMeshes[i]->ContentChanged();
			MeshRenderer *pR = NULL;
			for (unsigned int r = 0; pR = aMeshes[i]->ChildByClass<MeshRenderer>(r); ++r)
			{
				pR->OnMeshChange(MeshRenderer::changeVertexPosition);
				pR->OnVertexPositionChange(-1, -1);
			}
		}
		pG->ChangeActiveLevel(pActiveLevel); 
		pG->ContentChanged();
	}
	Kernel()->ViewPort()->Redraw();
	Kernel()->Interface()->RefreshUI();
} 