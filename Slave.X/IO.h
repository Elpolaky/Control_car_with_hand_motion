/* 
 * File:   IO.h
 * Author: HELAL
 *
 * Created on December 22, 2021, 11:20 PM
 */

#ifndef IO_H
#define	IO_H

#define _PA   0
#define _PB   1
#define _PC   2
#define _PD   3


#define Led0   PC2
#define Led1   PC7
#define Led2   PD3

#define ON  1
#define OFF 0

#define OUT 1
#define IN  0


// PORT Level
void setPortDir(int portNum, int state);
void setPortData(int portNum, int data);
void togglePortData(int portNum);
// Pin Level

void setPinDir(int portNum, int pinNum,int state);
void setPinData(int portNum, int pinNum, int data);
void togglePinData(int portNum, int pinNum);



#endif	/* IO_H */

