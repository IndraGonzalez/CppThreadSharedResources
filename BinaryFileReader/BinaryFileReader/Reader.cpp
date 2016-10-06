#include "Reader.h"
#include<qfile.h>
#include<qdatastream.h>
#include<qdebug.h>

Reader::Reader(QObject *parent)
	: QThread(parent)
{
	stopReading = false;
}

void Reader::run()
{
	QFile file("//srv01/PracticasProgramacion/Datos/Kalman/20160809_141552.std");
	//int count = 100000;
	if (file.open(QIODevice::ReadOnly)) {
		QDataStream in(&file);
		in.setByteOrder(QDataStream::LittleEndian);
		while ((!in.atEnd()) && (!stopReading)) {
			
			Value value;
			int temp;
			in >> value.time;
			
			in >> temp;
			value.spinX = temp * 0.1;

			in >> temp;
			value.spinY = temp * 0.1;

			in >> temp;
			value.spinZ = temp * 0.1;
		
			in >> temp;
			value.speedX = (temp * 0.05) / pow(2.0, 15.0);

			in >> temp;
			value.speedY = (temp * 0.05) / pow(2.0, 15.0);

			in >> temp;
			value.speedZ = (temp * 0.05) / pow(2.0, 15.0);

			/*value.speedX = (value.speedX*pow(2, 15)) / 0.05;
			value.speedY = (value.speedY*pow(2, 15)) / 0.05;
			value.speedZ = (value.speedZ*pow(2, 15)) / 0.05;

			value.spinX = value.spinX / 0.1;
			value.spinY = value.spinY / 0.1;
			value.spinZ = value.spinZ / 0.1;*/

			//qDebug() << word;
			
			values.append(value);
			
			//words = file.readAll();

			//char *temp = new char[count];
			//in.readRawData(temp, count);
			//words.append(temp, count);
			//delete[] temp;
		}
	}

	for (int i = 0; i < values.size(); i++)
	{
		if (stopReading) break;
		qDebug() << "_____________";
		qDebug() << values[i].time;
		qDebug() << values[i].spinX;
		qDebug() << values[i].spinY;
		qDebug() << values[i].spinZ;
		qDebug() << values[i].speedX;
		qDebug() << values[i].speedY;
		qDebug() << values[i].speedZ;
	}
	
}
Reader::~Reader()
{
}

void Reader::stop() 
{
	stopReading = true;
}

