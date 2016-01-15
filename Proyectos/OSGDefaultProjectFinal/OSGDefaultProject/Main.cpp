#include <osg/Node>
#include <osg/Group>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Texture2D>
#include <osgDB/ReadFile> 
#include <osgViewer/Viewer>
#include <osg/PositionAttitudeTransform>
#include <osgGA/TrackballManipulator>
#include <osg/Material>
#include "Todos_Los_Marcianos.cpp"
#include "Torreta.cpp"
#include "Disparos.cpp"
//#include "keyboard.cpp"

int derechaaux;
int Tamaño_Cubos;
osgViewer::Viewer viewer;
osg::Group* root;
int altura_nave;
int altura_marcianos;
int derecha;
int MAX_der;
int MIN_der;
bool movimientoDerecha;
osg::PositionAttitudeTransform* NaveForm = new osg::PositionAttitudeTransform();
osg::PositionAttitudeTransform* MarcianosForm = new osg::PositionAttitudeTransform();
TMarcianos* Marcianos;
int posTorreta;
int alturaaux;
int alturaDisparos;
Disparos* DisparosNave;
int TechoDisparos;
int yInicialDisparos;
int xInicialDisparos;
int tamañoBloque;
bool Starter;

class KeyboardEventHandler : public osgGA::GUIEventHandler
{
public:

    KeyboardEventHandler()
    {}


	virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter&)
	{
		switch(ea.getEventType())
		{
			case(osgGA::GUIEventAdapter::KEYDOWN):
			{
				switch (ea.getKey()) 
				{
					case 's':
						if (posTorreta<=MAX_der*15)
							posTorreta=posTorreta+15;
						return true;
					case 'a':
						if (posTorreta>=MIN_der*15)
							posTorreta=posTorreta-15;
						return true;
					case 'p':
						if (Starter)
						DisparosNave->addDisparo(posTorreta+xInicialDisparos,0,yInicialDisparos,Tamaño_Cubos);
						return true;
					case 't':
						Starter=true;
						return true;
					
				}
			}
			default:
				break;
				
		}
		//return false to allow mouse manipulation
		return false;
	}

private:
	int posicion;
};

void inicia()
{
derechaaux=0;
Tamaño_Cubos=5;
altura_nave=0;
altura_marcianos=100*Tamaño_Cubos;
alturaDisparos=0;
derecha=0;
MAX_der=100;
MIN_der=-100;
tamañoBloque=0;
movimientoDerecha=true;
posTorreta=0;
NaveForm =new osg::PositionAttitudeTransform();
MarcianosForm=new osg::PositionAttitudeTransform();

	//root = new osg::Group();
}

void ConfigurarLuz0()
{
	osg::Group* LucesGrupo = new osg::Group();
osg::Light* light = new osg::Light();
//light->setDirection(osg::Vec3d(0.0,0.0,0.0));
//	light->setPosition(osg::Vec4d(125.0, 0.0, 125.0, 1.0));
	osg::LightSource * lightsource = new osg::LightSource();
	lightsource->setLight(light);

	LucesGrupo->addChild(lightsource);
	lightsource->setStateSetModes(*LucesGrupo->getOrCreateStateSet(), osg::StateAttribute::ON);
	root->addChild(LucesGrupo);
}


void generaArbol()
{
	root = new osg::Group();
//	Configurar_Material();
	//generar marcianos
	Marcianos=new TMarcianos(0,altura_marcianos,Tamaño_Cubos);
	root->addChild(MarcianosForm);
    MarcianosForm->addChild(Marcianos->getMarcianos());
	TechoDisparos=Marcianos->Techo;
	//generar nave
	torreta* Nave=new torreta(Marcianos->cDm,0,0,Tamaño_Cubos*2);
	altura_nave=Nave->top;
	yInicialDisparos=Nave->yDisparo;
	xInicialDisparos=Nave->xDisparo;
	root->addChild(NaveForm);
    NaveForm->addChild(Nave->gettorreta());

	DisparosNave= new Disparos();
	root->addChild(DisparosNave->getDisparos());
	// switch off lighting as we haven't assigned any normals.
	ConfigurarLuz0();
	//root->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	int iterador=0;
	viewer.addEventHandler(new KeyboardEventHandler());
		viewer.setSceneData( root );
	   viewer.setCameraManipulator(new osgGA::TrackballManipulator());
    viewer.realize();
    //The final step is to set up and enter a simulation loop.


    //viewer.run();

}



bool calcular_movimiento()
{
	int MAX_derparcial=(MAX_der)*2-((Marcianos->limder)+100);
	int MIN_izqparcial=(MIN_der)*2-((Marcianos->limizq)-100);
	int despalazamiento=1+((Marcianos->LineasMuertas()+Marcianos->filabordex2())/2);
	if (movimientoDerecha)
		derecha=(derecha+despalazamiento);
	else derecha=(derecha-despalazamiento);
	int derechaauxi=derecha+tamañoBloque;
	int izquierdaauxi=derecha;
	if (movimientoDerecha&&(derechaauxi>=MAX_derparcial)) {
												movimientoDerecha=false;
												return true;
												}
	if (!movimientoDerecha&&(izquierdaauxi<=MIN_izqparcial)) {
												movimientoDerecha=true;
												return true;
												}
	return false;

}

void actualizaArbol()
{
	osg::Vec3 MarcianosPosition(derecha,0,alturaaux);
    MarcianosForm->setPosition( MarcianosPosition );
    //viewer.run();

  //  viewer.setCameraManipulator(new osgGA::TrackballManipulator());
  //  viewer.realize();
	osg::Vec3 NavePosition(posTorreta,0,0);
	NaveForm->setPosition( NavePosition );

	if (alturaDisparos<TechoDisparos)
	{
	DisparosNave->actualizaDisparo(alturaDisparos);
	if (DisparosNave->exixte()) 
		if (Marcianos->Actualizar(DisparosNave->getX(),DisparosNave->getY(),alturaaux,derecha))
			if(DisparosNave->removeDisparo())
				alturaDisparos=0;
	}
	else if (DisparosNave->removeDisparo())
		alturaDisparos=0;
//Nave->Actualizar(posTorreta,0,Tamaño_Cubos*2);
}

bool disparosExiste()
{
	return DisparosNave->_exixt;
}

void seteaBack()
{
	/*
//NEW
	////////////////////////////////////
	osg::Texture2D* KLN89FaceTexture = new osg::Texture2D;

   // protect from being optimized away as static state:
   KLN89FaceTexture->setDataVariance(osg::Object::DYNAMIC); 

   // load an image by reading a file: 
   osg::Image* klnFace = osgDB::readImageFile("KLN89FaceB.bmp");

   // Assign the texture to the image we read from file: 
   KLN89FaceTexture->setImage(klnFace);
	/////////////////////////////////////////
    if (!klnFace)
   {
	osg::Image* klnFace = osgDB::readImageFile("KLN89FaceB.bmp");
	}
   // Create a new StateSet with default settings: 
   osg::StateSet* stateOne = new osg::StateSet();

   // Assign texture unit 0 of our new StateSet to the texture 
   // we just created and enable the texture.
   stateOne->setTextureAttributeAndModes
      (0,KLN89FaceTexture,osg::StateAttribute::ON);
   // Associate this state set with the Geode that contains
   // the pyramid: 
   //pyramidGeode->setStateSet(stateOne);
   viewer->getCamera()->setClearColor();
   //////////////////////////////////
   */
}

int main()
{	
	Starter=false;
	inicia();
	generaArbol();
	seteaBack();
	int Tope=altura_nave;
	int Altura_Actual_Marcianos=altura_marcianos;
	alturaaux=0;
	alturaDisparos=0;
	MAX_der=(Marcianos->limder+100);
	tamañoBloque=Marcianos->limder;
	while( !viewer.done()&& (Altura_Actual_Marcianos>=Tope)&& !(Marcianos->isVacio()) )
    {
        viewer.frame();
		if (Starter)
			{
			if (disparosExiste()) alturaDisparos=alturaDisparos+5;
			if (calcular_movimiento())
			{
			alturaaux=alturaaux-10;
			Altura_Actual_Marcianos=alturaaux+(Marcianos->limiteInf);
			}
		}
		actualizaArbol();
		//generaArbol();

    }

    return 0;
}
