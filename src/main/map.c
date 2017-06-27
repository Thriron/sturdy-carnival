
#define MAP_SIZE 16

/*          0001
 *         ______
 *        |      |
 *  1000  |[x][y]| 0010
 *        |______|
 *
 *          0100
 */ 
#define UP 0x01
#define DOWN 0x04
#define LEFT 0x08
#define RIGHT 0x02
uint8_t map[MAP_SIZE][MAP_SIZE];

int map_init(){
    memset(map, 0, sizeof(map));
    //initialize walls
    for(int i=0; i<MAP_SIZE; i++){
        map[i][0] |= UP;
        map[i][MAP_SIZE] |= DOWN;
        map[0][i] |= LEFT;
        map[MAP_SIZE-1][i] |= RIGHT;
    }
}

void set_walls(uint8_t wall, uint8_t x, uint8_t y){//TODO: mark walls as visited
    map[x][y]=wall;
    if((wall & UP)!=0){
        if((y+1) < MAP_SIZE){
            map[x][y+1]|= DOWN;
        }
    }
    if((wall & DOWN)!=0){
        if((y-1) >= 0){
            map[x][y-1]|= UP;
        }
    }
    if((wall & RIGHT)!=0){
        if((x+1) < MAP_SIZE){
            map[x+1][y]|= LEFT;
        }
    }
    if((wall & LEFT)!=0){
        if((x-1) >= 0){
            map[x-1][y]|= RIGHT;
        }
   }
}

void main(){
    init();
}
