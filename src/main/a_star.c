
typdef struct _location {
    int x;
    int y;
} Location;

Location * nav_stack;
int nav_stack_size, nav_stack_current_size;

add(Location pos){
    int i,j;
    int distance;
    distance = distance(pos);
    for(i=0; i<nav_stack_current_size; i++){
        if(distance < distance(nav_stack[i])){
            //copy down
            if(nav_stack_size == nav_stack_current_size){
                nav_stack_size *= 2;
                //realloc;
            }
            nav_stack_current_size++;
            //for(j=i; j<nav_stack_current_size; j++)
            for(j=nav_stack_current_size; j>i; j--){
                nav_stack[j] = nav_stack[j-1];
            }
            //insert
            nav_stack[i] = pos;
            return;
        }
    }
    //add to end
    if(nav_stack_size == nav_stack_current_size){
        nav_stack_size *= 2;
        //realloc
    }
    nav_stack_size++;
    nav_stack[nav_stack_size] = pos;
}
