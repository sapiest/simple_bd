#include <stdio.h>
#include <stdlib.h>
#include "auth.h"
#include "pathfinder.h"
#include "define.h"

int main() {
    static t_member members[SIZE_TABLE];
    static t_member *requested;
    initialize_mem(members);
    while(1) {
        printf("\nДобро пожаловать в упрощенную систему администрирования(beta)\n"
                       "Введите команду:\n"
                       "1:<-Доступ в личный кабинет гражданина РФ->\n"
                       "2:<-Поиск ближайшего пункта гуманитарной помощи->\n"
                       "3:<-Узнать текущего главу правительства РФ->\n"
                       "0:<-Для выхода->\n");
        int response = 0;
        scanf("%d", &response);
        switch (response) {
            case 0: {
                if(outputDECODER) remove(outputDECODER);
                return 0;
            }
            case 1:
                requested = NULL;
                while (1) {
                    if (!auth(&requested, members))
                        break;
                }
                break;
            case 2:
                pathfinderInit();
                break;
            case 3:
                MrPresident();
                break;
            default:
                printf("Неверная кнопка!");
        }
    }
}