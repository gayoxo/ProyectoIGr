#include "Marciano.cpp"
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

class TMarcianos {
private:
	osg::Group* LMarcianos;
	osg::Vec3* Array;
	bool boolArray[50];
	int lineas_vivas;
	osg::StateSet* stateset;
	osg::Material* material;
public:
	int cDm;
	int Techo;
	int Xini;
	int Xfinal;
	int limder;
	int limizq;
	int limiteInf;
	int filborde;


	TMarcianos(int x,int y,int tamaño)
	{
	stateset =new osg::StateSet;
	material = new osg::Material;
	LMarcianos = new osg::Group();
	Configurar_Material();
	Array=new osg::Vec3[50];
		int arrai=0;
	int Y=y;
	int X=x;
	Xini=x;
	limizq=0;
	lineas_vivas=10;
	limiteInf=y;
	filborde=0;
	int iniIzq=x;
	marciano* M;
	osg::PositionAttitudeTransform* MarForm;
	M=new marciano(X,0,0,tamaño);
	//LMarcianos->addChild(M->getMarciano());
	int Ascension_malla=0;
	int derecha_malla=0;
	for (int j=0;j<5;j++)
	{
		if (j!=0)
				{
				Y=Y+M->top+tamaño;
				}
		X=x;
	for (int i=0;i<10;i++)
	{
		if (i!=0)
			X=X+M->right+(tamaño*2);


		MarForm = new osg::PositionAttitudeTransform();
		osg::Vec3 NavePosition(X,0,Y);
		MarForm->addChild(M->getMarciano());
		MarForm->setPosition( NavePosition );
		LMarcianos->addChild(MarForm);
		//M=new marciano(X,0,Y,tamaño);
		Array[arrai]=osg::Vec3(X,Y,tamaño);
		boolArray[arrai]=true;
		arrai++;
		//LMarcianos->addChild(M->getMarciano());
	}
	}
	X=X+M->right;
	Y=Y+M->top;
	int inider=X;
	Techo=Y;
	limder=X;
	cDm=((inider-iniIzq)/2);
	Xfinal=X;
	 stateset->setAttributeAndModes(material,osg::StateAttribute::OVERRIDE|osg::StateAttribute::OFF);
	}

	osg::Group* getMarcianos()
	{
	return LMarcianos;
	}

	bool Actualizar(int x,int y,int altura_respecto_al_origen,int desviacion_a_la_derecha)
	{
		unsigned int iterador_marcianos=0;
		unsigned int iterador_Array=0;
		bool _Matado=false;
		while(iterador_marcianos<LMarcianos->getNumChildren())
		{
			while (!boolArray[iterador_Array]) iterador_Array++;
			if (Colision(x,y,Array[iterador_Array],altura_respecto_al_origen,desviacion_a_la_derecha))
				{
				LMarcianos->removeChild(iterador_marcianos);
				boolArray[iterador_Array]=false;
				Calcular_laterales();
				return true;
				}
			else iterador_marcianos++;
			iterador_Array++;
		}
	return false;
	}
	
	bool isVacio()
	{
		if (LMarcianos->getNumChildren()==0) return true;
		else return false;
	}

	void Calcular_laterales()
	{
		lineas_vivas=0;
		int auxiliar=limizq;
		limizq=limder;
		limder=auxiliar;
		for(int i=0;i<10;i++)
		{
			if (linea_viva(i))
			{
				lineas_vivas++;
				int limderaux=Array[i].x() + Array[i].z()*marciano.columnas;
				int limizqaux=Array[i].x();
				if (limderaux>limder)
					limder=limderaux;
				if (limizqaux<limizq)
					limizq=limizqaux;
			}
		}
		int iteratdorfil=0;
		while ((iteratdorfil<50)&&!(boolArray[iteratdorfil]))
			iteratdorfil++;
		filborde=iteratdorfil/10;
		limiteInf=Array[iteratdorfil].y();
	}



	bool linea_viva (int linea)
	{
		int ite=0;
		while (ite<5)
		{
			if (boolArray[((ite*10)+linea)])
				return true;
			ite++;
		}
		return false;
	}

	bool Colision(int x,int y,osg::Vec3 vector,int altura_respecto_al_origen,int desviacion_a_la_derecha)
	{
		int BOTTON=vector.y()+altura_respecto_al_origen;
		int TOP=vector.y()+(vector.z()* marciano.filas)+altura_respecto_al_origen;
		int LEFT=vector.x()+desviacion_a_la_derecha;
		int RIGTH=vector.x()+(vector.z()*marciano.columnas)+desviacion_a_la_derecha;
		if ((y<=TOP)&&(y>=BOTTON)&&(x>=LEFT)&&(x<=RIGTH))
			return true;
		else return false;
	}

	int LineasMuertas()
	{return 10-lineas_vivas;}

	int filabordex2()
	{
	return (filborde)*2;
	}

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
		LMarcianos->setStateSet(stateset);
}


};