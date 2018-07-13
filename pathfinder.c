//
// Created by Dwarf on 24.06.2018.
//
#include <stdio.h>

int n;

int FindLowestWay(int w[n][n], int peopleCount[n]);

void pathfinderInit(){
    FILE *in;
    in = fopen("CityMap.txt", "r");
    fscanf(in,"%d", &n);
    int peopleCount[n];
    for (int i = 0; i < n; i++){
        fscanf(in,"%d", &peopleCount[i]);
    }
    int w[n][n];
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fscanf(in,"%d", &w[i][j]);
        }
    }
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if ((w[i][j] > w[i][k] + w[k][j] && w[i][k] != -1 && w[j][k] != -1)||(w[i][j] == -1 && w[i][k] != -1 && w[j][k] != -1)){
                    w[i][j] = w[i][k] + w[k][j];
                }
            }
        }
    }
    printf("Наиближайщий пункт помощи в городе %d по списку", FindLowestWay(w, peopleCount));
    fclose(in);
}

int FindLowestWay(int w[n][n], int peopleCount[n]){
    int NumSchool = 0;
    int LowestWay = 9999999;
    int CurrWay;
    for (int i = 0; i < n; i++){
        CurrWay = 0;
        for (int j = 0; j < n; j++){
            CurrWay += w[i][j] * peopleCount[j];
        }
        if (CurrWay < LowestWay){
            LowestWay = CurrWay;
            NumSchool = i;
        }
    }
    return (NumSchool);
}

void MrPresident(){
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddxxxxxxxxxxddddddddddddxdddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddxxxxxxxxxxxdddddddddddddddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddddddddddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddddddddddddddddddddddddddddd\n"
                   "xxdxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddddddddddddddddddddddddd\n"
                   "xxxdddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddddddddddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddddddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddxxxdddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddddddddddddddddddddddddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddoolllccllllccccclllllloolllloooodddddddddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddoolcc:::::::::::;;;::::ccccccccccccccccllllooodddddddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdxddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddollcc::;;;;;:;;;;;;;;;::::::cccccccccccccccccccccccllllllooddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddol:;;;,,,;;;;;;;;;;;;;;:::::ccccccllllllllllllllcccccccc::::::clodxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddol:;;,,,,,,,;,;;;;;;;;:;::cccccllllllllooooollllllllllccllccc::;;,;:lodxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddxdddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddlc:,,,,,,,,,,;;;;;;;:::cccccllllllooooooooooooodooolllllcc:cccc::;;,'',:lddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddxxxxdddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddlc;,,,;;;;,,;::::::::ccccccclllllooooooooooooooooooooooooollccccc:;;,,''',;:loddddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddxxxxxxxxxdddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddol:;,,,,;;;;;;;;::cccccccccllllllllooooooooooooooooooooddddddddooollcc::;;;;;,,',;cloddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddxxxxxxxxdddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddol:;,,,,,,;;;;;;::ccccccccccllllllloooooooooddoooooodddddddxxxxxxxxxddoollc::c::;,''',;coddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddlc;,,'''''',,;;::cccccclllcllllllllllloooooddddddddddxxxxxxxxxxxxxxxxxxxxxdollllc::;,''',;coddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddoc:,'''...'',;:cccccllllllllllllloooooooooodddddddddxxxxxkkkkkxxxkkxxxxxxxxxxxxddoolc::;,,'',:ldddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddl:;,'''..',;::ccllllllllllllllooooooodooddddddddddxxxxxxxxxkxxxkkxxxxxxxxxkkkxxxxxxxddoc::;,'',:loddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdoc:;,,''',,;:ccllllllllllloooooooodoodddddddddxxxxxxxxxxkkkkkxxxxxxxxkkxxxxxkkkkkkkxxkxxxdoc:;,,,,;codddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdlc::;,,,,;;:cllllllllllllllooooooodddddddddddxxxxxxxkkkkkkkkkkkkkxxxxxxxkkkkkkkkkkkkkxxkkkxdoc:;;;;:ccodddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxoc:::;,,;;:clllllllllllllllooooodddddddddddddxxxxxkkkkkkkkkkkkkkkkxxkkkkkkkkkkkkkkkkkkkkkkxxxdlc:;:cllclddddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxolcc:;;;;:cloolllclllllllllloooodddddddddddddxxxxxxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxxdl:;:ccllldxxddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxkdoolc;,;;:loooolllllllclllllloooddddddddddddddxxxxxxxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxdl:;:cloodxkxdxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxkxoooc;;;;cloddoollllllllllllloooddddddddddddddxxxxxxxxkkkkkkkkkkkkkkkkkkkkkkkkOOOOkkkkkkkkkkkkkkkkxoc:;:loddxkkxdxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxkkdooc::::cloddddollllllcccllloooodddddddddxxxxxxxxxxxxkkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOkkkkkkkkkkkxdlc::cldddxkkddxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdxkxdolc::cclodddddolccllllccllloooddddddxxxxxxxxxxxkkkxkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOkkkkkkkkkkkxdlcclodxxdxxxdxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddddxdddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxkkxdolcccccoddddddollcclllcclllooodddddxxxxxxxxxxxxkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkkkxolllooxxddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxkkxxddollclodddddddollcccllccllllooodddxxxxxxxxxxxxkkkkkkkkkkkkkkkkOOOOOOOOOOO00000OOOOOOOOOOOkkkkkkkkkkxdooolodxddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxkOxdxxddollloddddddddlccccccccllllloodddxxxxxkkkkxxxkkkkkkkkkkkkkkOOOOOOOOOOO00000000OOOOOOOOOOkkkkkkkkkkkxdddoodddddkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxOOxxxxddolloooddddddolccccccccclllloodddxxxxxkkkkkkkkkkOkkkOOOkkkkOOOOOOOO000000000O00OOOOOOOOOkkkkkkkkkkxxxxxdoodddxkkxdxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxkkkxxxxxdoooooodddoooollccccccccclllooodddxxxxxkkkkkkkkkkkkkkkkkkkOOOOO00000000000000OOOOO00OOOOkkkkkkkkkkxxxxxxdooddxxkxdxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxooooollooooooollcccccccccllooodddxxxxxxkkkkkkkkkkkkkkkkkkkOOOOO00000000000000OOOOOOOOOOOkkkkkkkkkkkkxxkxxdooooxkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdxxxxxxxdddoolloooolloolcccccclcclloooodddxxxxxkkkkkxkkkkkkkkkkkkkkOOOOOOOO00000000000OOOOO00OOkkkkkkkkkkkkkkkkxxkdooodxkxxxxxxxxxxxxxxxxxxxxxxxxxxdddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdxxxxxxxxxdddolloddolloolccccclllllloddoooddxxxxkkkkkxkkkkkkkkkkkkkkOOOOOO000000000000000OOOOOOOkkkkkkkkkkkkkkOOkkxxddoodkkxxxxxxxxxxxxxxxxxxxxxxxxxdddddxdddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdxxxxxddooooooddolloollcccccllllloddoooddxxxxxkkkkxxxkkkkkkkkkkkkOOOOOOO00000000000000000OOOOOkkkkkkkkkkkkkkOkkxxddoooxkxxxxxxxxxxxxxxxxxxxxxxxxxxddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdxddxdoooooooooollloollccccllllllooooooddddxxxkkkkkkkkkkkkkkkkkkkkOOOOOOO0OOOOO00000000000OOOkkkkkkkkkkkkOkkkkkxxxdooddxxdxxxxxxxxxxxxxxxxxxxxxxxxxxddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddxdolooollllllllllollccccllllllloooooddddxxxxkkkkkkkkkkkkkkkkkkkOOOOOOOOOOOOOO00000OOO00OOOkkkkkkkkkkkkOkkkkkxxxxddddxddxxxxxxxxxxxxxxxxxxxxxxxxxxxdxdddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddooodddllcccllodoolllloolccccclllllllooooooddxxxkkkkkkkkkkkkkxkkkkkOOOOOOOOOOOO0000000OOO000OOOkkkkkkkkkkkkkkkkkkxxxxddddddddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddoooddollcclodddddoooooolccclllllllolloooooodxxxkkkkOOOOOkkkkxkkkkOOOOOOOOOOOO000000000000000OOOkkkkkkkkkkkkkkkkkxxxddoodooodxddxxxxxxxxxxxxxxxxxxxxxxxxxxddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddoooooooolclddddxxdoooooolclllllllllloooooooodddxxxkkOOOOOOkkkkkkkkOOOOOOOOOO000000000000000000OOkkkkkkkkkkkkkkkxxxdddoddooldkkkxddxxxxxxxxxxxxxxxxxxxxxxxxxxxdddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxkolloooooolccodddxxxddddddoolllllllllloooodoooooddddxxkkOOOOOkkkkkkkOOOOOOOOOOO000000000000000000OOOkkkkkxkkkkkxxxxxxxdddddodkkkxxxxdxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddocclooooollclodddxxxdoodddoollloollllloodddooooddodddxxkkkkOkkkkkkkkkkkkOkOOOOOOOOOOOOOOO0OO00000OOOkkkkkxxkkkkkkkxxxddddddxOOkdccxxddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdoc,;clllllllllodddxxxoooxdoolcclllcccclllllllllllllooooddxxxxxxxxxxkkkxxkkkxxxxxdddxdddddxxddxxkOOOOOkkkkkkxxkkkkxxxddddddxxkOkxoloxkddxxxxxxxxxxxxxxxxxxxxxxxxddxxxx\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddoc;;:clllllllodddddddddddolccccc:::::::;,,,,,,,;;:ccllooddxxxddddxxxxxxxddolllc::::ccccllooooddxxkkkkkkkkkxkkkkkkkxddddddxxxxkkdookkddxxxxxxxxxxxxxxxxxxxxxxxdddddxd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddl:;;:ccllllldxddddddooooc:::;::;;;,,,''........',,;;:clloddddddddxxdolllcc:;,''''',,;;;;:ccllodddddxxxkkkkkkkkkkkxddooddxxkkOOxookkxdxxxxxxxxxxxxxxxxxxxxxxdddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddoc:::cllcllodxxxdoolccc:;;;;;;;,,,'''''''''''.'''''',,;:loodddddxxxdlccc:;;;,,,;;;;:ccccc::::cllooodddxkkkkkkkkkkxddodxdxO00OOxodkkddxxxxxxxxxxxxxxxxxxxxxddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddlc::ccccloodxddoolc:;;;,,,,,;;,,,,;;;:cc:::;;,,,,,,''';cloddxxxkkkxdolcllc::::ccccccloodddoc:clloooddxxkkkkxkkkkxxddddddkOOOOxdkOxdxxxxxxxxxxxxxxxxxxxxxxxxddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddocc;::;:clodddddolc:::;;;;,,',,,',,''',,;;;;;;;;;;;,'',:lodxkOOOOkxxolcllccc:::;,'..';;cooooolloddxkkOOOkkkkkkkkxxxdddlldxkOOxxOxdxxxxxxxxxxxxxxxxxxxxxxxxxxxddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddoc:::;;,:oxdddxdolcccc::;;,'''',:,''...'';::;;::::;,,,;codxkOOOOOkxdolooolccllc::'';:cxkxddddxkkOOOO0OOOOkkkkkkxxxxxooddxOOOxkxddxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddoc:cc:;;oxxddxdlccllcc::;,',;::cc;;;,,;coolc::ccllc;,,:ldxOO00OkkkOkkxddoooddollclloxOOOOkOOOOOOO0000OOOOkkkkkxxxkkkkkkkkOOkkddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddolllllloddddddolllllccc::;::clooolllooddoolccllolc;,,:ldxkO00OOkkOOkkxddddddxdxxxxkkOOOOOOOOOOOO00000OOOkkkxxxxxO00OOOO00Okxdxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddoddoodxdddxxdolllllllccccccllodddxxxxdddollllllc:;;;:coxkO000OkkOOkxxxdddddxkkOOOOOO00OOOOOOOOOO000OOOkkkkxxxxkO00000000Okddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddooooodddddddolccllllllccllooddxxxkkkxddoollcc::::;;:codkO00OOOOOOkkxxxkxxxkkkkkkkOOOOOOO00000000000OOkkxxxxxxkOOOOOOO00Oxdxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddoolccodoodddolcclloolllloddddddxxxxxxdddoolccc:::;;:cldkOO00OOOOOOOOkkkkkkkkOOOOOOOOOOOOO0000000000OkkxxxxxdxkkkkOOkOOOkddxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddodolcldoooooolcllllooooooddxxxxxxdddddddoolllc::::::coxkOO00OOOOOOO0OOOOkkkkOOOOOOOOOOOOO0000000OOOOkkxxxxddxkkkkOOkxkkxdxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddollllodoloollcccllloooooddddddddddxxddddoolcc:::::cloxkO0000OOOOOO000OOOOOOkkkkOOOOOOO00000000OOOkkkxxxxddxkkOOOOkkkOkddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddolcccldollllccccccclllloodddddddddxxxxxddolcc:::::cloxkOOO00OOOOOO000OOOOOOOOOOOOOO00000000OOOOOkkxxxdddddxxkkkkkkOOkddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddolcccoollllc::cccccclllooodddddddxxxxxdoolc:::;::codxkOOO0OOOOOOOO00OOOkOOOOOOOOOOOOO0OOOOkkkkkkxxxddddddxkkOOOO00kddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddollloocccc:::::::::cclloooooddddxxxddoollc::;;:clodxkOOO00OOOOOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkxxxxddddddkOOO0000Oxdxxxxxxxxxxxxxxxxxxxxxxxxxxddxxdddddxxdd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdxxooodlc::::;;;:::::::cccllooodddxdddoolll:;;;::clodxkkOOOOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkkkxxxxxdddddddkOOOOOOOxddxxxxxxxxdxxxxxxdxxxxxxxdddddddddddddxdd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddoooolc::::::;;:::::::cccllooooddoooolllc:;;;::clodxkkOOOOOOOOOkkkkOOOkkkkkkOOOOOOOOkkkkkxxxxxxxxxddddddkOOOOkkxddxxxxxxxxddddxxxxxxxxxxxxdxdddddddddddxdd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddolllc:;:::::;;::::::ccllllooooooolllllc;;;;::cloxxkOOOOOOOOOOOkkkkkkkkkkkkkkkOkOOkkkkkkkkkxxxxxxdddddddxxxxxddxxxxxxxxxxxddxxxxxxxxxxxxxxxdddddddddxxddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddool::;:::::;;:::::cclllllllllllllllc:;;::::cloxkOOOO00OOOOOOOOkkxxkkkkkkkkkkkkOOkkkkkkkkxxxxxxddddxxddddddxxxxxxxxxxxxxxxxxxxxxxxxdxxxdddddddddddxxxdd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddoc:::::::;;::::::cclllllllllllllcc:;:::::cldxkOOO0000OOOOOOOOkkxkkkkkkkkkkkkkkkkkkkkkkkkxxxxdddxxxddxxxxxxxxxxxxxxxxxxxxxxxxxxdddddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddoc;;;::;;;;;:::::ccllllllllllllllc;;;:::ccldxkkOOO00OOOOOOOOOkkkkkkkkkkkkkkkkkOOOOkkkkkkxxxdddxxxxddxxxxxxxxxxxxxxxxxxxxddxddddddddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddl:;;;;;;;;:::::::cccccccllllllllc;,,,,;;:cooddxxxkOkkkkdddxxxxkkkkkkkkkkOOOOOOOOOkkkkkkkxxddxxxxxddxxxxxxxxxxxxdddxxxxxdddddxddxddxxxdddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddl::;;;;;;;;::::::cccccccclllllllcc;,'''',:cccclooxxkxoc::codxkkkkkkkkkkkOOOOOOOOOkkkxkkxxxxxxxxxddxxxxxxxxxxxxxdxdxxxxxxxxddxdddddddddddxdddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddlc:;;;;;;;;;::::::::cccccclllcccccc::;,'.',:::::cldxxxxxdodkkkkkkkkkkkkkkOOOOOOOkkkkkkkxxxxxxxxxddxdxxxxxddxxxxdddddddddddddxddxddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddoc::;;;;,,;;::::::::::cccccccccccccccc::;,,,,;;;:ldxkkkOkkkOOkkOOOOkkkOkkkkkOOOOkkkkkkkxxxxxxxxxddxxxxxdxddxddddddddddxddddddxxxxxxdddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdoc:;;;;;;;;;;:;;:::::::ccccccccccccccccc::ccc:::codxkkkOOkOOOkkOOOOOOOOkkkkkkkkkkkkkkkkkxxxxxxxxddxxxdddddddddxdddddxxxxdddddxxdddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddl:;;;;::;;;;;;;;;::::::::ccccccccccccccccoool:::ldxkkkkOOOOOOOOOOOOOOkkOkkkkkkkkkkkkkkkxxxxxxxxddxxddddddddddxdddddxxxxxddxxxddddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddoc;;;;::::;;;;;::::::::::cccccccccclllllldxxoc::coxkkkkkkkkOkkkkkkkkkkkkkkkkkkkkkkxkkkkxxxxxkxddxxddddddddddddddddddddxxddddddxddddddddxdddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdoc:;;;;::::;;:::::::::::cc:::::::ccllooodxkkxollldxxkkkkkkkkkkxxxxxxkkkkkxkkkkkkkxxkkkxxxxxxxxddxddddddddddddddddxdddddxxddddxxxxddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddoc;;;;::::::::::::;;;;:::::;;;;::ccllooddxkkxddddxxkkkkxxxxxdddoooodxxxxxxkkkkkkxxkkkxxxxxxxddxxdddddddddddddddddddxddddddddddddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddl:;;;;:::::::::::;;;;,,,,,,''',',,,,,;;;:lodooollloodddooooolc:;;:cloodxxkkkkkxxxkkxxdxxxxdddxddddddddddddddddddddxxxxddddddddddddxddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdoc;,,;;::::::c::;;;;,,,,''''''''..''',,,,,;::::::::cllloooooolcc:;;:clodxkkkkkxxxkkxddxxxddxxddxdddddddddxxdddddddddxxddddddxxdddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdoc;,;;;::::::::;;;;;;;;;;;,,,,;;;;::cclllllloooddddxxxxxddxxxxxdollllodxxkkkxxxkkxdddxddddxddxxdddddddddddddddddddddxxxddddddxddddddddxxddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdol:,,,;;:::;::;;;;;;;;:;;::;,,,,;;;::ccccccccccllooodddxxxkkkkkxxddoooddxxxxxxxkxxddddddddddddddddddddddddddddddddxdxxxxdddddddddddddxxdddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddoxxc,,,,,;:::;;;;;;;;::;;;:::;;;;;;,,,,,,,,,,,,;;::cloddxxkkkkkkkxxxxddddxxxxxxkxxdoxxddddddddddddddxdddddddddddxxdddddddxdddddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdoc;ck0kc,,,,,;::;;;,,;;;;:::::::::::::::ccccccllllllllooddxxkkkkkkkkkxxxxxxxxxxxxxxdoodxdddddddddddddxxxxxdddddddddxxxxdddddddddddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdl;..o000ko;''',;;;;;;,;;;;;;:::::::cclllooooodddxxxkkxxxxxxxxxkkkkkkkkkkxxxxxdddxxxdddxxxddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddc,. 'x0000Od:,''',;;,,,,;;;;;;::clllloooooooddddxxxkkOOOkkkkkkkkkkkkkkkkkxxxdddddddoddxxkxddddddddddddddddddddddddddddddddddddddxdddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdo:'.  .oO00000ko:'''',,''',,,,;;::cllooooooooddddddddxkkOOOOkkkkkkkkkkkkkxxddddoooooodxxxxkxddddddddddddddddddddddddddddddddddddddxddddxddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddl;.     ;xO00000Oko;'''''''''',,;;;::clllloooooddddoooddxkkkOkkkkkkkkkkxxxxddoooolloddxxxxxxdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdl:'.      .cxOOO00000ko:,''''''''',,;;;::ccclllloooddollooddxxxxxxxxxxxxxdddoooollloddxxkxxxxxdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdo:'.         .lxkOOO00000Odc,''''''''',,,;;;::ccccclloollllloooddddddddddddoooolloooddxkkkkxxxk0kddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdo:'.            .lkkOOOO000000xl;,,,,''',,,,,,;;;::::cccccccccclllllllooooolllllooddddxxkkkkkxxkKN0lcodddddddddddddddddddddddddddddddddddddddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddl:'.               .lkkOOOO0000KK0Odc;;;,,,,,,,,,;;;:::ccccccccccccc::::ccccclllooodddxxkkkkkkkxkKWWXl.,codddddddddddddddddddddddddddddddddddddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdoc;'.                  .ckOOOOO000KKKKK0koc;;;;:::;;:;;;::::::c::::::::::::::ccllooddxxxxkkkkkkkkxx0NWWNo...;lddddddddddddxdddddddddddddddddxxddddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddl:'..                     .:xOOOO0000KKKKKKKOxlc:::ccccc:::ccccccccccccccccccccllloddxxxkkkkkkkkkkkkOXWWWNd. ..':lddddddddddxddddddddddddddddddddddddddddxddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxddolc;,..                          ,dOOO00000KKKKKKKK0Odlcccclccccccccc:ccccccccclllooooddxxxxkkkkkkkkkkkkkKNWWNNx.    .':lddddddddddddddddddddddddddxdddddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxxxxxxdddolc:;'...                               .lkO000000KKKKKKKKKK0kdollllllooooolllllclllooodddddxxxkkkkkkkkkkkkkkk0NWWWNNO'      ..;codddddddddddxdddddddddddxxddddddddddddddddddddd\n"
                   "xxxxxxxxxxxxxxxxddolc;,'...                                      .:kO00000KKKKKKKKKKKKK0kxdoooddddxxxxxddoooooddddxxxxkkkxxkkkkkkOOOO0NWMWNNNKl..       .':coddddddddxddddddddddxxxxdddxxddddddddddddddd\n"
                   "xxxxxxxxxxxddolc;'...                                              ,dO0000KKKKKKKKKKKKKKKK0OkxdddxxkkkkkkkxxxddddddxxxxxkkkkkkkkOOOO0NWMWWNNNXOl..         ..';:cloddddddxdddxdxxdxxdddxxxxxdddddddddddd\n"
                   "xxxxxxddolc:;'..                                                    'dO000KKKKKKXXXXXXXXXXXXXK0OOkkxxkkkkkkkkkkkxxxxxxxxxkkkkkkOOOOKNMMMWWNNNXKOc.              ..',;cloodddddddxxdddddxdxxxdddddddddddd\n"
                   "xxddol:;,...                                                         'x000KKKKKXXXXNNNNNWWWWWNNNNNXKK00OOkkkkkkkkkkxxxxxkkkkkkkkkOXWMMMWWWWNNXXKx,..                ....',:clooddddddddxdxddddxddddddddd\n"
                   "cc:,'...                                                              ;k00KKKKKXXXXNNNWWWWWWWWWMMMMWWWWWNXXK0OkkkkkkkkkkkkkOOkxx0NWMMMMWWWWWNNXK0l.                       ....';:clooddddddddddddddddddd\n"
                   "....                                                                  .:k00KKKKKXXXNNNWWWWWWWMMMMMMMMMMMMMMMWNX0OkkkkxxkkOkxxxOXWMMMMMMWWWWWNNXKXO;.                            ....',:clodddddddddddddd\n"
                   "                                                                       .cO0KKKKKKXXNNNNWWWWWWMMMMMMMMMMMMMMMMMMMWXK0kxxxxxxxOXWMMMMMMMMMWWWWNNXXXXx'                                  ....,;:loodddddddd\n"
                   "                                                                        .o0KKKKKKXXXNNNNWWWWWMMMMMMMMMMMMMMMMMMMMMMWNKKK00KXWWMMMMMMMMMMMWWWNNXXXXKl.                                       ...,;:cloddd\n"
                   "                                                                         .dKKKKKKXXXNNNNWWWWWWMMMMMMMMMMMMMMMMMMMMNK0OkxxxooxOKNMMMMMMMMWWWWWNNXXXXO:.                                           ...',;:\n"
                   "                                                                         .'xKKKKKXXXNNNNNWWWWWWMMMMMMMMMMMMMMMMWXkl:;;,,,,'',,;ld0NMMMMMWWWWWNNXXXXXx,.                                                 \n"
                   "                                                                          .;kKKKKXXNNNNNNWWWWWWWMMMMMMMMMMMMMWXkl:;;;;;;,,,'''',,,cdKWMMWWWWWNNNXXXNKo.                                                 \n"
                   "                                                                           .:OKKXXNNNNNNNNWWWWWWWMMMMMMMWWMWXxc;;;,,;;;;;;;,,,'''''';lONWWWWWNNNNXXNNO:.                                                \n"
                   "                                                                            .c0XXXNNNNNNNNWWWWWWWWWMWWWWMMXx:',,',,',,,,;;;;,,,''''''',dKWWWWNNNNNXNNXd'.                                               \n"
                   "                                                                            ..lKXNNNNNNNNNWWWWWWWWWWWWWMNk:.......'''',,;;;;;,,''''...,cdOXWWNNNNNNNNN0c.                                               \n"
                   "                                                                             ..dXNNNNNNWWWWWWWWWWWWWWWNOc'...........'',,;;;;;;,,'''..:dxdx0NWNNNNNNNNXx,.                                              \n"
                   "                                                                              .'xNNNNNNWWWWWWWWWWWWWWKxc,''............'',;;;::;;,''.'lkkkxdkKNNNNNNNNNKl.                                              \n"
                   "                                                                              ..,kNNNNNNWWWWWNNWWWWNXKOkdl;''...........'',;;:::;,,'.,okOOkkxxOXNNNNNNNXk;.                                             \n"
                   "                                                                               ..;0NNNNNNNNNNNWWWNNNWNX0OOkdc,''..........',;;:::;,'.:O00OOOkkxk0NNNNNNNKl.                                             \n"
                   "                                                                                ..cKNNNNNNNNWWNNNNWWWWNX000K0xo:,''.........,,;::;,'.oNNXXK00OOkkOXNNNNNXk;.                                            \n"
                   "                                                                                 ..lXNNNNNNWNXXXNNWWWWNNX00KKK0Oxl:''........',;::;''xWWWWNNNK0OOOOKXNNNN0l.                                            \n"
                   "                                                                                 ...dXNNNWWNXXXXNNWWWWNNNXKKXXKKK0Odc,'.......',::;,'xWWWWWWWWNXK0000XNNNKx,.                                           \n"
                   "                                                                                  ..'xNNWWWNNNNXNNNWWWWNNNXKXXXXKKKK0kl;'......';:;,'oNWWNNNWWWWNXKK00KXNNOc.                                           \n"
                   "                                                                                   ..,OWWWWWWNNNNNNNWWWWNNNNXNXXXXXKKK0kc''......';;;dXWNNNNNWWWNWNNNXKKKNXx,                                           \n"
                   "                                                                                    ..:0WWWWWWNNNNNNNNWWNNWNNNNXXXXXKKKKd,.......';::;xNNNNNNWWWNNWWWWWNXK0Ol.                                          \n"
                   "                                                                                    ...cKNNWWWWNNNNNNNWWWNNWNNNNXXKKKKX0c........';::':0NNNWWWWWNNNWWWWWNXOkd,                                          \n"
                   "                                                                                     ...oXNNWWWNNNNNNNNWWNNNNNNNXXKKKKKd'.'......';:;',kNNNNWWWWWNNNWWWWNX0xd:.                                         \n"
                   "                                                                                      ...dXNNNNNNNNNNNNWWWNNNNNNNXKKKKk;..'......';::,'dNNNNNWWWWWNNNWWWWNKkxl.                                         \n"
                   "                                                                                       ..,xXNNNNNNNNNNNWWWNNNNNNNXK000l..........';:;,'cKWNNNNNWWWNNNNWWWNKOxd;                                         \n"
                   "                                                                                       ...;OXXNNNNNNNNWWWWWNNNNXNNXK0x,..........',::;',kNWWWNNNNWWNNNNWWNXOkxc.                                        \n"
                   "                                                                                        ...c0XXNNNNNNNWWWWWNNNNNNNNX0l...........',::;,'lXWNWWWNNNNNNNNNNNX0kko'                                        \n"
                   "                                                                                         ...lKXXNNNNNWWWWWWWNNNNNNNXk;...........';::;,',kNNNNWWNNXXNNNNNNNKkkx:.                                       \n"
                   "                                                                                          ..'dKXXNNNNNWWWWWWWNNNNNNXd'...........';::;;,'cKNNNNWWWNNXXXNNNNKOkkl.                                       \n"
                   "                                                                                           ..,kKXXNNNNWWWWWWWWNNNNNKl............';;::;,',xNNNNNNWWWNNXXNNNXOkkd,                                       \n"
                   "                                                                                           ...;OXXXNNNNWWWWWWWWNNNN0:............',;::;;,'cKNNNNNNWWWNNXXXNX0kxx:.                                      \n"
                   "                                                                                            ...c0XXXNNNWWWWWWWWNNNNk;............',::::;;',xNNNNNNNWWWNNNXXXKOxxo.                                      \n"
                   "                                                                                            ....oKXXXNNNWWWWWWWNNNXx,............',;:::;;,'c0NXNNNNNWWWNNNXXX0xxd,                                      \n"
                   "                                                                                             ...'xKXXXNNNWWWWWWNNNXd,............',;;:::;;',xNNXNNNNNWWWNNNXXKkdd:.                                     \n"
                   "                                                                                              ...,kXXXXNNWWWWWWNNNXd,''..........',;:::::;,'c0NXXXNNNNWWWNNNXX0xdl.                                     \n"
                   "                                                                                               ...:0XXXNNNWWWWWNNNXd,''..........'',;::::;;',dXNXXXNNNNNWWNNNXKkdo'                                     \n"
                   "                                                                                                ...lOKXXNNWWWWWNNNNx;''..........',,;::::;;,';kNNXXXNNNNNWNNNNX0xo;.                                    \n"
                   "                                                                                                 ...,oKXNNNWWWWWNNXd,'...........',,;::::;;,'':ONNXXXXNNNNNNNNNXkdc.                                    \n"
                   "                                                                                                 ....'xXXNNNWWWWNNKo,'...........',,;;::::;;,''cONNNXXNNNNNNNNNN0xl'                                    \n"
                   "                                                                                                  ....,kXNNNWWWWNNKo,'...........',,,;;:::;;,'',c0NNNXXNNNNNNNNNXko;                                    \n"
                   "                                                                                                   ....;0NNNNWWWNNKo,'...........',,,,;:::;;,''',l0NNNXXXNNNNNNNN0x:.                                   \n"
                   "                                                                                                     ...cKNNNWWWNNKo,'..........'',,,,;;::;;,,'.',oKNNNXXXXNNNNNNKkl.                                   \n"
                   "                                                                                                      ...oXNNWWWNN0o,'..........'''',,,;::;;;,'.'';dXNNNXXXXNNNNNXOd,                                   \n"
                   "                                                                                                       ..'xNNNWWNN0o,''..........''',,,;;;;;;,''.',;xXNNNXXXXXNNNXOx:                                   \n"
                   "                                                                                                       ...,ONNWWNN0o,''.........''',,,;:::;;;,,'..',:kNNNNXXXXXNNX0kc.                                  \n"
                   "                                                                                                        ...lXWWWWN0o,''..........''''';:::;;;;,'..',;lKNNNNXXXXXXX0ko.                                  ");
}
