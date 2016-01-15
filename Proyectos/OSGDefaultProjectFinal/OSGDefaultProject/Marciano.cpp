#include "cubo.cpp"
#include <osg/Node>
#include <osg/Group>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Texture2D>
#include <osgDB/ReadFile> 
#include <osgViewer/Viewer>
#include <osg/PositionAttitudeTransform>
#include <osgGA/TrackballManipulator>

class marciano {
private:
	osg::Group* Marciano;
public:
	int boton;
	int top;
	int left;
	int right;
	static const int filas=8;
	static const int columnas=11;

	marciano(int x, int y, int z,int tama�o)
	{
	Marciano = new osg::Group();
	boton=z;
	left=x;
	top=(8*tama�o)+z;
	right=(11*tama�o)+x;
	int xlinea=x;
	int fila0=0;
	int fila1=tama�o*1; //5
	int fila2=tama�o*2;	//10
	int fila3=tama�o*3;	//15
	int fila4=tama�o*4;	//20
	int fila5=tama�o*5;	//25
	int fila6=tama�o*6;	//30
	int fila7=tama�o*7;	//35
	int mu=tama�o;
	//vertical1
	cubo* cubomio=new cubo (xlinea,y,fila1+z,tama�o);
	cubo* cubomio2=new cubo(xlinea,y,fila2+z,tama�o);
	cubo* cubomio3=new cubo(xlinea,y,fila3+z,tama�o);
	//vertical2
	xlinea=xlinea+tama�o;
	cubo* cubomio4=new cubo(xlinea,y,fila3+z,tama�o);
	cubo* cubomio5=new cubo(xlinea,y,fila4+z,tama�o);
	//vertical3
	xlinea=xlinea+tama�o;
	cubo* cubomio6=new cubo(xlinea,y,fila1+z,tama�o);
	cubo* cubomio7=new cubo(xlinea,y,fila2+z,tama�o);
	cubo* cubomio8=new cubo(xlinea,y,fila3+z,tama�o);
	cubo* cubomio9=new cubo(xlinea,y,fila4+z,tama�o);
	cubo* cubomio10=new cubo(xlinea,y,fila5+z,tama�o);
	cubo* cubomio11=new cubo(xlinea,y,fila7+z,tama�o);
	//vertical4
	xlinea=xlinea+tama�o;
	cubo* cubomio12=new cubo(xlinea,y,fila0+z,tama�o);
	cubo* cubomio13=new cubo(xlinea,y,fila2+z,tama�o);
	cubo* cubomio14=new cubo(xlinea,y,fila3+z,tama�o);
	cubo* cubomio15=new cubo(xlinea,y,fila5+z,tama�o);
	cubo* cubomio16=new cubo(xlinea,y,fila6+z,tama�o);
	//vertical5
	xlinea=xlinea+tama�o;
	cubo* cubomio16bis=new cubo(xlinea,y,fila0+z,tama�o);
	cubo* cubomio17=new cubo(xlinea,y,fila2+z,tama�o);
	cubo* cubomio18=new cubo(xlinea,y,fila3+z,tama�o);
	cubo* cubomio19=new cubo(xlinea,y,fila4+z,tama�o);
	cubo* cubomio20=new cubo(xlinea,y,fila5+z,tama�o);
	//vertical6
	xlinea=xlinea+tama�o;
	cubo* cubomio21=new cubo(xlinea,y,fila2+z,tama�o);
	cubo* cubomio22=new cubo(xlinea,y,fila3+z,tama�o);
	cubo* cubomio23=new cubo(xlinea,y,fila4+z,tama�o);
	cubo* cubomio24=new cubo(xlinea,y,fila5+z,tama�o);
	//vertical7
	xlinea=xlinea+tama�o;
	cubo* cubomio24bis=new cubo(xlinea,y,fila0+z,tama�o);
	cubo* cubomio25=new cubo(xlinea,y,fila2+z,tama�o);
	cubo* cubomio26=new cubo(xlinea,y,fila3+z,tama�o);
	cubo* cubomio27=new cubo(xlinea,y,fila4+z,tama�o);
	cubo* cubomio28=new cubo(xlinea,y,fila5+z,tama�o);
	//vertical8
	xlinea=xlinea+tama�o;
	cubo* cubomio29=new cubo(xlinea,y,fila0+z,tama�o);
	cubo* cubomio30=new cubo(xlinea,y,fila2+z,tama�o);
	cubo* cubomio31=new cubo(xlinea,y,fila3+z,tama�o);
	cubo* cubomio32=new cubo(xlinea,y,fila5+z,tama�o);
	cubo* cubomio33=new cubo(xlinea,y,fila6+z,tama�o);
	//vertical9
	xlinea=xlinea+tama�o;
	cubo* cubomio34=new cubo(xlinea,y,fila1+z,tama�o);
	cubo* cubomio35=new cubo(xlinea,y,fila2+z,tama�o);
	cubo* cubomio36=new cubo(xlinea,y,fila3+z,tama�o);
	cubo* cubomio37=new cubo(xlinea,y,fila4+z,tama�o);
	cubo* cubomio38=new cubo(xlinea,y,fila5+z,tama�o);
	cubo* cubomio39=new cubo(xlinea,y,fila7+z,tama�o);
	
	//vertical10
	xlinea=xlinea+tama�o;
	cubo* cubomio40=new cubo(xlinea,y,fila3+z,tama�o);
	cubo* cubomio41=new cubo(xlinea,y,fila4+z,tama�o);

	//vertical11
	xlinea=xlinea+tama�o;
	cubo* cubomio42=new cubo(xlinea,y,fila1+z,tama�o);
	cubo* cubomio43=new cubo(xlinea,y,fila2+z,tama�o);
	cubo* cubomio44=new cubo(xlinea,y,fila3+z,tama�o);

	xlinea=xlinea+tama�o;
	left=xlinea;

	Marciano->addChild(cubomio->getCube());
	Marciano->addChild(cubomio2->getCube());
	Marciano->addChild(cubomio3->getCube());
	Marciano->addChild(cubomio4->getCube());
	Marciano->addChild(cubomio5->getCube());
	Marciano->addChild(cubomio6->getCube());
	Marciano->addChild(cubomio7->getCube());
	Marciano->addChild(cubomio8->getCube());
	Marciano->addChild(cubomio9->getCube());
	Marciano->addChild(cubomio10->getCube());
	Marciano->addChild(cubomio11->getCube());
	Marciano->addChild(cubomio12->getCube());
	Marciano->addChild(cubomio13->getCube());
	Marciano->addChild(cubomio14->getCube());
	Marciano->addChild(cubomio15->getCube());
	Marciano->addChild(cubomio16->getCube());
	Marciano->addChild(cubomio16bis->getCube());
	Marciano->addChild(cubomio17->getCube());
	Marciano->addChild(cubomio18->getCube());
	Marciano->addChild(cubomio19->getCube());
	Marciano->addChild(cubomio20->getCube());
	Marciano->addChild(cubomio21->getCube());
	Marciano->addChild(cubomio22->getCube());
	Marciano->addChild(cubomio23->getCube());
	Marciano->addChild(cubomio24->getCube());
	Marciano->addChild(cubomio24bis->getCube());
	Marciano->addChild(cubomio25->getCube());
	Marciano->addChild(cubomio26->getCube());
	Marciano->addChild(cubomio27->getCube());
	Marciano->addChild(cubomio28->getCube());
	Marciano->addChild(cubomio29->getCube());
	Marciano->addChild(cubomio30->getCube());
	Marciano->addChild(cubomio31->getCube());
	Marciano->addChild(cubomio32->getCube());
	Marciano->addChild(cubomio33->getCube());
	Marciano->addChild(cubomio34->getCube());
	Marciano->addChild(cubomio35->getCube());
	Marciano->addChild(cubomio36->getCube());
	Marciano->addChild(cubomio37->getCube());
	Marciano->addChild(cubomio38->getCube());
	Marciano->addChild(cubomio39->getCube());
	Marciano->addChild(cubomio40->getCube());
	Marciano->addChild(cubomio41->getCube());
	Marciano->addChild(cubomio42->getCube());
	Marciano->addChild(cubomio43->getCube());
	Marciano->addChild(cubomio44->getCube());
	};

	osg::Group* getMarciano()
	{
	return Marciano;
	}


};
