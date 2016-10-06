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
			
			values.append(value);

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

