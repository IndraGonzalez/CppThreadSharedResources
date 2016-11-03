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
	QFile file("//srv01/PracticasProgramacion/Datos/Kalman/Set2/20160614_082114.std");

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
			value.speedX = ((double)temp * 0.05) / pow(2.0, 15.0);
			//value.speedX = ((double)temp * pow(2.0, 15.0))/ 0.05 ;

			in >> temp;
			value.speedY = ((double)temp * 0.05) / pow(2.0, 15.0);
			//value.speedY = ((double)temp * pow(2.0, 15.0)) / 0.05;

			in >> temp;
			value.speedZ = ((double)temp * 0.05) / pow(2.0, 15.0);
			//value.speedZ = ((double)temp * pow(2.0, 15.0)) / 0.05;
			
			values.append(value);
		}
	}
	writeDataFile();
}


void Reader::writeDataFile() {

	QFile file("C:/Users/igonzalez/Desktop/DatosKalman/datosIMU.txt");
	if (file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QTextStream out(&file);
			
		for (int i = 0; i < values.size(); i++)
		{
				out.setRealNumberNotation(QTextStream::FixedNotation);
				out.setRealNumberPrecision(3);
				out << values[i].time << "\t";
				out.setRealNumberPrecision(2);
				out << values[i].spinX << "\t";
				out << values[i].spinY << "\t";
				out << values[i].spinZ << "\t";
				out.setRealNumberPrecision(8);
				out << values[i].speedX << "\t";
				out << values[i].speedY << "\t";
				out << values[i].speedZ << endl;
		}
	}
	file.close();
	exit();
}