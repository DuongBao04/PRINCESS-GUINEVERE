#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}

int size_line2;
string line2[1000];
string line3[3];

void adventureToKoopa(string file_input, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue) {
    
    take_knight_info(file_input, HP, level, remedy, maidenkiss, phoenixdown);
    take_journey_info(file_input);
    take_file_pack(file_input);


    const int Arthur = 1;
    const int Lancelot = 2;

   
    string file_mush_ghost = line3[0];
    string file_asclepius_pack = line3[1];
    string file_merlin_pack = line3[2];


    rescue = -1;
    const int maxHP = HP;
    int tiny = -1;
    int currentlv = -1;
    int frog = -1;
    int mode = 0;
    bool checksk19 = 0;
    bool checksk18 = 0;

    //CheckThanPhanHiepSi
    {
        if (maxHP == 999)
        {
            mode = Arthur;
        }
        if (checknguyento(maxHP) == true)
        {
            mode = Lancelot;
        }
    }

    //DongSuKien
    for (int i = 0; i < size_line2; i++)
    {
        long long event = stoi(line2[i]);

        //event0
        if (event == 0)
        {
            event_0(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            break;
        }

        //event1-5 : Giao Tranh
        if (event == 1 || event == 2 || event == 3 || event == 4 || event == 5)
        {
            //CheckThanPhanHiepSi
            if (mode == Arthur || mode == Lancelot)
            {
                if (level < 10)
                {
                    level++;
                }

                if (i == size_line2 - 1 && HP > 0) {
                    rescue = 1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
            }

            if (mode != Arthur && mode != Lancelot)

            event_1to5(event, i + 1, HP, level, remedy, maidenkiss, phoenixdown, rescue);

        }

        //event6 : Giao Tranh
        if (event == 6)
        {

            //CheckThanPhanHiepSi
            if (mode == Arthur || mode == Lancelot)
            {
                level += 2;
                if (level > 10) level = 10;

                if (i == size_line2 - 1 && HP > 0) {
                    rescue = 1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
            }

            //CheckTrangThai
            if (frog > 0 || tiny > 0)
            {
                frog--;
                tiny--;

                if (tiny == 0)
                {
                    HP = HP * 5;
                    if (HP > maxHP) HP = maxHP;
                    tiny--;
                }

                if (frog == 0)
                {
                    level = currentlv;
                    frog--;
                }
                if (i == size_line2 - 1 && HP > 0) {
                    
                    rescue = 1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }

                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                continue;
            }

            if (mode != Arthur && mode != Lancelot) {
                int temp = HP;

                event_6(event, i + 1, HP, level, remedy, maidenkiss, phoenixdown, rescue);

                //TinyMode
                if (temp > HP)
                {
                    tiny = 4;
                }
            }
        }

        //event7 : Giao Tranh
        if (event == 7)
        {

            

            //CheckThanPhanHiepSi
            if (mode == Arthur || mode == Lancelot)
            {
                level += 2;
                if (level > 10) level = 10;

                if (i == size_line2 - 1 && HP > 0) {
                    rescue = 1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
            }

            //CheckTrangThai
            if (frog > 0 || tiny > 0)
            {
                frog--;
                tiny--;

                if (tiny == 0)
                {
                    HP = HP * 5;
                    if (HP > maxHP) HP = maxHP;
                    tiny--;
                }

                if (frog == 0)
                {
                    level = currentlv;
                    frog--;
                }

                if (i == size_line2 - 1 && HP > 0) {
                    
                    rescue = 1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }

                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                continue;
            }
            if (mode != Arthur && mode != Lancelot) {

                currentlv = level;

                event_7(event, i + 1, HP, level, remedy, maidenkiss, phoenixdown, rescue);

                //FrogMode
                if (level == 1) frog = 4;
            }
        }

        //event11
        if (event == 11)
        {

            event_11(event, i + 1, HP, level, remedy, maidenkiss, phoenixdown, rescue);

            // display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
        }

        //event12
        if (event == 12)
        {
            event_12(event, i + 1, HP, level, remedy, maidenkiss, phoenixdown, rescue);

        }

        //event15-Remedy
        if (event == 15)
        {
            if (remedy < 99)
                remedy++;
        }

        //event16-maidenkiss
        if (event == 16)
        {
            if (maidenkiss < 99)
                maidenkiss++;
        }

        //event17--phoenixdown
        if (event == 17)
        {
            if (phoenixdown < 99)
                phoenixdown++;
        }

        //event13-MushGhost
        if (event > 100)
        {
            bool checkdie = 0; 
            string sukien = to_string(event);

            for (int i = 2 ;i<sukien.length();i++)
            {

                event_13(file_mush_ghost, sukien[i], HP, level, remedy, maidenkiss, phoenixdown, rescue);
                
                if (HP > maxHP) HP = maxHP;
                if (HP <= 0 && phoenixdown > 0)
                {
                    HP = maxHP;
                    phoenixdown--;
                }
                else if (HP <= 0 && phoenixdown == 0)
                {
                    checkdie = 1;
                    break;
                }

            }
            if (checkdie == 1)
            {
                rescue = 0;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                break;
            }
        }

        //event99 - Giao Tranh
        if (event == 99)
        {

            //CheckThanPhanHiepSi
            if (mode == Arthur)
            {
                level = 10;

                if (i == size_line2 - 1 && HP > 0) {
                    rescue = 1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }

                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                continue;
                
            }
            if (mode == Lancelot)
            {
                if (level >= 8)
                {
                    level = 10;

                }
            }

            if (level == 10)
            {
                if (i == size_line2 - 1 && HP > 0) {
                    rescue = 1;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }

                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                continue;
            }

            if (level < 10)
            {
                rescue = 0;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                break;
            }
        }

        //event19
        if (event == 19 && checksk19 == 0)
        {
            event_19(file_asclepius_pack, HP, level, remedy, maidenkiss, phoenixdown, rescue);
            checksk19 = 1;
        }

        //event18
        if (event == 18 && checksk18 == 0)
        {
            event_18(file_merlin_pack, HP, level, remedy, maidenkiss, phoenixdown, rescue);
            checksk18 = 1;
        }

        //KetThuc1Round
        {
            if (HP <= 0)
            {
                if (phoenixdown >= 1)
                {
                    tiny = 0;
                    frog = 0;

                    phoenixdown--;
                    HP = maxHP;
                }
                else if(phoenixdown < 1)
                {
                    rescue = 0;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
            }

            if (tiny > 0) tiny--;
            if (frog > 0) frog--;

            if (tiny == 0)
            {
                HP = HP * 5;
                tiny--;
            }

            if (frog == 0 && currentlv != -1)
            {
                level = currentlv;
                frog--;
            }
            if (HP > maxHP) HP = maxHP;

            if (remedy > 99) remedy = 99;
            if (maidenkiss > 99) maidenkiss = 99;
            if (phoenixdown > 99) phoenixdown = 99;
           

            if (tiny > 0 && remedy > 0)
            {
                tiny = -1;
                HP = HP * 5;
                remedy--;
            }
            if (frog > 0 && maidenkiss > 0)
            {
                frog = -1;
                level = currentlv;
                maidenkiss--;
            }

            if (i == size_line2 - 1 && HP > 0) rescue = 1;

            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
        }

    }   

}

  

//read knight info (line 1);
void take_knight_info(string file_input, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown) {
    ifstream file;
    file.open(file_input, ios::in);

    file >> HP >> level >> remedy >> maidenkiss >> phoenixdown;

    file.close();
}

//read journey info (line 2)
void take_journey_info(string file_input) {

    ifstream file;
    file.open(file_input, ios::in);

    string s1, s2, s3;

    getline(file, s1);
    getline(file, s2);
    getline(file, s3);

    int count = 0;
    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] == ' ') count++;

    }

    int n = count + 1;

    int k = 0, current = 0;
    for (int i = 0; i <= s2.size(); i++) {
        if (s2[i] == ' ' || s2[i] == '\0') {
            string numIns = s2.substr(current, i - current);
            line2[k] = numIns;
            k++;
            current = i + 1;
        }
    }
    size_line2 = n;

    file.close();
}

//read packs info (line 3)
void take_file_pack(string file_input) {
    ifstream file;
    file.open(file_input, ios::in);

    string s1, s2, s3;

    getline(file, s1);
    getline(file, s2);
    getline(file, s3);

    int k = 0, current = 0;
    for (int i = 0; i <= s3.size(); i++) {
        if (s3[i] == ',' || s3[i] == '\0') {
            string numIns = s3.substr(current, i - current);
            line3[k] = numIns;
            k++;
            current = i + 1;
        }
    }
    file.close();
}

//Su Kien 0
void event_0(int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue) {
    rescue = 1;
}

//level0
int level0(int eventnumber) {
    int lv;
    int b = eventnumber % 10;

    lv = eventnumber > 6 ? (b > 5 ? b : 5) : b;

    return(lv);
}

//Su Kien 1 Toi 5
void event_1to5(int masukien, int eventnumber, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue) {

    int damage;

    switch (masukien)
    {
    case(1): damage = 1 * level0(eventnumber) * 10;; break;
    case(2): damage = 1.5 * level0(eventnumber) * 10;; break;
    case(3): damage = 4.5 * level0(eventnumber) * 10;; break;
    case(4): damage = 7.5 * level0(eventnumber) * 10;; break;
    case(5): damage = 9.5 * level0(eventnumber) * 10;; break;
    }


    if (level > level0(eventnumber))
    {
        if (level < 10)
            level += 1;
    }
    if (level < level0(eventnumber))
    {
        HP = HP - damage;
    }
}

//Su Kien 6
void event_6(int masukien, int eventnumber, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue) {
    if (level > level0(eventnumber))
    {
        level += 2;
            if (level > 10) level = 10;
    }
    if (level < level0(eventnumber))
    {
        //Bien thanh ty hon
        if (remedy > 0) {
            remedy--;
        }
        if (remedy < 1) {
            if (HP < 5) HP = 5;
            HP = HP / 5;
        }
    }
}

//SirenVajsh -- su kien 7
void event_7(int masukien, int eventnumber, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue) {
    if (level > level0(eventnumber))
    {
        level += 2;
        if (level > 10) level = 10;
    }
    if (level < level0(eventnumber))
    {
        //BienThanhEch
            level = 1;
    }
}

//MushMario --su kien 11
void event_11(int masukien, int eventnumber, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue) {
    int n1 = ((level + phoenixdown) % 5 + 1) * 3;
    int temp = 99;
    int s1 = 0;

    for (int i = 1; i <= n1; i++)
    {
        s1 = s1 + temp;
        temp -= 2;
    }
    HP = HP + (s1 % 100);

    do {
        HP++;
    } while (checknguyento(HP) == false);
}

//checknguyenTo
bool checknguyento(int a)
{
    if (a == 2) return true;
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0) return false;
    }
    return true;
}

//FibonacciMushFibo
void event_12(int masukien, int eventnumber, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue) {
    int temp = 1;
    long long arr[100];
    int i = 2;
    int a = 1;
    
    if (HP > 1)
    {
        while (temp < HP)
        {
            a = temp;
            arr[0] = 1;
            arr[1] = 1;
            arr[i] = arr[i - 1] + arr[i - 2];
            temp = arr[i];
            i++;
        }
    }
    HP = a;
}

//Su Kien 13
void event_13(string file, char type, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue)
{
    ifstream mushghostpack;
    mushghostpack.open(file);

    string n2, s;
    
    getline(mushghostpack, n2);
    getline(mushghostpack, s);

    //n2 la number
    int number = stoi(n2);
    long long mang[100];
    int a = 0, j = 0;

    for (int i = 0; i <= s.length(); i++)
    {
        string temp;
        if (s[i] == ',' || s[i] == '\0')
        {
            temp = s.substr(a, i - a);
            a = i + 1;
            mang[j] = stoi(temp);
            j++;            
        }
    }

    switch (type)
    {
        case(49):
        {
            int maxi, mini;
            long long max = -9999999, min = 9999999;  
            for (int i = 0; i <number; i++)
            {
                if (mang[i] >= max)
                {            
                    max = mang[i];
                    maxi = i;
                }

                if (mang[i] <= min)
                {
                    min = mang[i];
                    mini = i;
                }
            }
            HP = HP - (maxi + mini);
            break;
        }

        case(51):
        {
            int maxi2, mini2;
            long long max = -9999999, min = 9999999;
            long long mang3[100];

            //BienDoi
            for (int i = 0; i < number; i++) {
                mang3[i] = mang[i];
            }
            for (int i = 0; i < number; i++)
            {
                if (mang3[i] < 0)
                {
                    mang3[i] *= -1;
                }
                    mang3[i] = (17 * mang3[i] + 9) % 257;
            }

            //ThucHien
            for (int i = 0; i < number; i++)
            {
                if (mang3[i] > max)
                {
                    max = mang3[i];
                    maxi2 = i;
                }

                if (mang3[i] < min)
                {
                    min = mang3[i];
                    mini2 = i;
                }
            }
            HP = HP - (maxi2 + mini2);
            break;
        }

        case(52):
        {
            int max2_3i = -1;
            long long max2_3x = - 99999999, max1_3x = -99999999;
            long long mang4[100];
            if (number == 1)
            {
                HP += 12;
                break;
            }

    

            //BienDoi
            {
                for (int i = 0; i < number; i++)
                {
                    mang4[i] = mang[i];
                }
                for (int i = 0; i < number; i++)
                {
                    if (mang4[i] < 0)
                    {
                        mang4[i] *= -1;
                    }
                    mang4[i] = (17 * mang4[i] + 9) % 257;
                }
            }

            if (mang4[0] == mang4[1] && mang4[0] == mang4[2])
            {
                HP += 12;
                break;
            }

            if (number == 2)
            {
                if (mang4[0] == mang4[1])
                {
                    HP += 12;
                    break;
                }
                else if (mang4[0] > mang4[1])
                {
                    max2_3x = mang4[1];
                    max2_3i = 1;

                    HP = HP - (max2_3x + max2_3i);
                    break;
                }
                else if (mang4[0] < mang4[1])
                {
                    max2_3x = mang4[0];
                    max2_3i = 0;

                    HP = HP - (max2_3x + max2_3i);
                    break;
                }
            }

            //TimSoLonThu1
            for (int i = 0; i < 3; i++)
            {
                if (max1_3x < mang4[i]) max1_3x = mang4[i];
            }

            //TimSoLonThu2
            for (int i = 0; i < 3; i++)
            {
                
                if (max2_3x < mang4[i] && mang4[i] < max1_3x)
                {
                    max2_3x = mang4[i];
                    max2_3i = i;
                }
            }

            if (max2_3i == -1)
            {
                max2_3x = -5;
                max2_3i = -7;
            }

            HP = HP - (max2_3x + max2_3i);
            break;
        }

        case(50):
        {
            int mtx, mti;
            bool checkTangdan = true;
            bool checkGiamDan = true;
            int max = - 9999999;
            int vitri = -1;
            bool checkNui = 1;

            for (int i = 0; i < number; i++)
            {
                if (max < mang[i])
                {
                    vitri = i;
                    max = mang[i];
                }
            }
            
            if (number == 1)
            {
                vitri = 0;
                max = mang[0];
            }

            else if (vitri == 0)
            {
                for (int i = 0; i < number - 1; i++)
                {
                    if (mang[i] <= mang[i + 1])
                    {
                        checkGiamDan = 0;
                        checkNui = 0;
                        break;
                    }
                }
            }

            else if (vitri == number - 1)
            {
                for (int i = 0; i < number - 1; i++)
                {
                    if (mang[i] >= mang[i + 1])
                    {
                        checkTangdan = 0;
                        checkNui = 0;
                        break;
                    }
                }
            }

            else if (vitri != -1)
            {
                for (int i = 0; i < vitri; i++)
                {
                    if (mang[i] >= mang[i + 1])
                    {
                        checkTangdan = 0;
                        checkNui = 0;
                        break;
                    }
                }

                for (int i = vitri; i < number - 1; i++)
                {
                    if (mang[i] <= mang[i + 1])
                    {
                        checkGiamDan = 0;
                        checkNui = 0;
                        break;
                    }
                }
            }

            if (checkNui == 1)
            {
                mtx = max;
                mti = vitri;
            }

            if (checkNui == 0)
            {
                mtx = -2;
                mti = -3;
            }

            HP = HP - (mtx + mti);
            break;
        }
    }
}

//Su Kien 19
void event_19(string file, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue)
{

    ifstream asclepius(file);
    int r1, c1;
    asclepius >> r1 >> c1;
    long long mang[100][100];

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            asclepius >> mang[i][j];
        }
    }

    for (int i = 0; i < r1; i++)
    {
        int count = 0;
        for (int j = 0; j < c1; j++)
        {
            if (mang[i][j] == 16)
            {
                remedy++;
                count++;
            }
            if (mang[i][j] == 17)
            {
                maidenkiss++;
                count++;
            }
            if (mang[i][j] == 18)
            {
                phoenixdown++;
                count++;
            }
            if (count == 3) break;
        }
    }
}

//Su Kien 18
void event_18(string file, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue)
{
    ifstream merlin(file);
    int n9;
    merlin >> n9;
    string temp;
    string s1 = "merlin";
    string s2 = "Merlin";
    string a;


    getline(merlin, a);

    for (int i = 0; i < n9; i++)
    {
        getline(merlin, temp);

        bool M = 0, E = 0, R = 0, L = 0, I = 0, N = 0;;

        if (temp.find(s1) >= 0 && temp.find(s1) < temp.length() || temp.find(s2) >= 0 && temp.find(s2) < temp.length())
        {
            HP += 3;
            continue;
        }
        for (int j = 0; j < temp.length(); j++)
        {

            if (temp[j] == 'M' || temp[j] == 'm') M = true;
            if (temp[j] == 'E' || temp[j] == 'e') E = true;
            if (temp[j] == 'R' || temp[j] == 'r') R = true;
            if (temp[j] == 'L' || temp[j] == 'l') L = true;
            if (temp[j] == 'I' || temp[j] == 'i') I = true;
            if (temp[j] == 'N' || temp[j] == 'n') N = true;


        }

        if (M == 1 && E == 1 && R == 1 && L == 1 && I == 1 && N == 1)
        {
            HP += 2;
        }
    }
    
}