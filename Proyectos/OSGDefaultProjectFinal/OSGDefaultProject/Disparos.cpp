#include "Disparo.cpp"
#include <osg/Node>
#include <osg/Group>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Texture2D>
#include <osgDB/ReadFile> 
#include <osgViewer/Viewer>
#include <osg/PositionAttitudeTransform>
#include <osgGA/TrackballManipulator>

class Disparos {
private:
	osg::Group* _Disparo;
	int _x;
	int _y;
	int _z;
	int _altura;
	int _tamaño;

public:

		bool _exixt;

	Disparos()
	{
	_Disparo = new osg::Group();
	_exixt=false;
		_x=0;
	_y=0;
	_z=0;
	_altura=0;
	_tamaño=0;
	};

	osg::Group* getDisparos()
	{
	return _Disparo;
	}

	void addDisparo(int x, int y, int z,int tamaño)
	{
	if (!_exixt){
	_x=x;
	_y=y;
	_z=z;
	_tamaño=tamaño;
	disparo* cubomio=new disparo (x,y,z,tamaño);
	_Disparo->addChild(cubomio->getDisparo());
	_exixt=true;
	}
	}
	
	void actualizaDisparo(int altura)
	{
		if (_exixt){
		disparo* cubomio=new disparo (_x,_y,_z+altura,_tamaño);
		_Disparo->replaceChild(_Disparo->getChild(0),cubomio->getDisparo());
		_altura=altura;
		}
	}

	bool removeDisparo()
	{
	if (_exixt){
	_x=0;
	_y=0;
	_z=0;
	_tamaño=0;
	_Disparo->removeChild(_Disparo->getChild(0));
	_exixt=false;
	return true;
	}else return false;
	}
	
	int getX()
	{
		return _x;
	}
	int getY()
	{
		return _z+_altura;
	}
	bool exixte(){return _exixt;}
};