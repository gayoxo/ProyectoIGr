#include "Nave.cpp"
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

class torreta {
private:
	osg::Group* Torreta;
	osg::Material*	material;
	osg::StateSet* stateset;
public:
	int boton;
	int top;
	int left;
	int right;
	int xDisparo;
	int yDisparo;

void Configurar_Material()
{
		// version which sets the color of the wireframe.
	    material->setColorMode(osg::Material::OFF); // switch glColor usage off
	    // turn all lighting off
		material->setShininess(osg::Material::FRONT_AND_BACK,10.0f);
	    material->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4(0.0,1.0f,0.0f,1.0f));
	    material->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4(0.0,1.0f,0.0f,1.0f));
	    material->setSpecular(osg::Material::FRONT_AND_BACK, osg::Vec4(0.0,1.0f,0.0f,1.0f));
	    // except emission... in which we set the color we desire
	    material->setEmission(osg::Material::FRONT_AND_BACK, osg::Vec4(0.0,0.0f,0.0f,1.0f));
	    stateset->setAttributeAndModes(material,osg::StateAttribute::OVERRIDE|osg::StateAttribute::ON);
	    stateset->setMode(GL_LIGHTING,osg::StateAttribute::OVERRIDE|osg::StateAttribute::ON);
		Torreta->setStateSet(stateset);
}

	torreta(int x, int y, int z,int tamaño)
	{
	Torreta = new osg::Group();
		material = new osg::Material;
		stateset =new osg::StateSet;
	//Configurar_Material();
	boton=y;
	left=x;
	//top=(8*tamaño)+z;
	//right=(11*tamaño);
	int	tamaño_cubo_grade=tamaño*5;
	nave* cubomio=new nave (x,y,z,tamaño_cubo_grade);
	int puntopunta=tamaño_cubo_grade;
	puntopunta=puntopunta/2;
	puntopunta=puntopunta-(tamaño/2);
	nave* cubomio2=new nave(x+puntopunta,y,tamaño_cubo_grade+z,tamaño);
	Torreta->addChild(cubomio->getNave());
	Torreta->addChild(cubomio2->getNave());
	top=tamaño_cubo_grade+tamaño+y;
	right=tamaño_cubo_grade+x;
	yDisparo=top;
	xDisparo=x+puntopunta;
		 stateset->setAttributeAndModes(material,osg::StateAttribute::OVERRIDE|osg::StateAttribute::OFF);
	};



	osg::Group* gettorreta()
	{
	return Torreta;
	}
	void Actualizar(int x,int y,int tamaño)
	{
	boton=y;
	left=x;
	//top=(8*tamaño)+z;
	//right=(11*tamaño);
	int	tamaño_cubo_grade=tamaño*5;
	nave* cubomio=new nave (x,y,0,tamaño_cubo_grade);
	int puntopunta=tamaño_cubo_grade;
	puntopunta=puntopunta/2;
	puntopunta=puntopunta-(tamaño/2);
	nave* cubomio2=new nave(x+puntopunta,y,tamaño_cubo_grade,tamaño);
	Torreta->replaceChild(Torreta->getChild(0),cubomio->getNave());
	Torreta->replaceChild(Torreta->getChild(1),cubomio2->getNave());
	top=tamaño_cubo_grade+tamaño+y;
	right=tamaño_cubo_grade+x;
	yDisparo=top;
	xDisparo=x+puntopunta;
	}
};