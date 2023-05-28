#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);
//void event_12(int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue);
int level0(int i);
void event_1to5(int masukien, int eventnumber, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue);
void event_0(int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue);
void event_6(int masukien, int eventnumber, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue);
void event_7(int masukien, int eventnumber, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue);
void event_11(int masukien, int eventnumber, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue);
bool checknguyento(int a);
void event_12(int masukien, int eventnumber, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue);
void take_knight_info(string file_input, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown);
void take_journey_info(string file_input);
void take_file_pack(string file_input);
void event_13(string file, char type, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue);
void event_19(string file, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue);
void event_18(string file ,int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue);
#endif // __KNIGHT_H__