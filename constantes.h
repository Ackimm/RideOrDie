#ifndef _CONSTANTES_H_
#define _CONSTANTES_H_


#define sec_in_millisec 1000
#define FPS 60
#define updateFrequency (sec_in_millisec/FPS)

/*#define updateNewEnemy 1000
#define enemySpeed 30
#define tirsSpeed 10
*/

#define updateNewEnemy 1000
#define enemySpeed updateFrequency
#define tirsSpeed updateFrequency


#define Square_size 10.0
#define Shoot_size 10.0
#define alternate_player_size 10

#define nbBestScores 5



#endif
