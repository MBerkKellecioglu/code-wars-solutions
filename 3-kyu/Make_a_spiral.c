int collide(int n, int spiral[n][n], int *pos, int *vel){
    if(spiral[pos[1] + vel[1] * 2][pos[0] + vel[0] * 2] == 1){
        return 1;
    }
    return 0;
}

int is(const int a[], int x, int y){
    return (a[0] == x && a[1] == y);
}

void spiralize (unsigned n, int spiral[n][n]){
    int pos[2] = {0,0}, velo[2] = {1,0};
    int temp_x, i, j;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            spiral[i][j] = 0;
        }
    }

    for(i = 0; i < n; i++){
        while(1){
            spiral[pos[1]][pos[0]] = 1;

            pos[0] += velo[0];
            pos[1] += velo[1];

            if (i > 2){
                if (collide(n, spiral, pos, velo)){
                  spiral[pos[1]][pos[0]] = 1;
                  break;
                }

            }
            else if (is(pos, n-1,0) || is(pos, 0,n-1) || is(pos, n-1,n-1)){
                break;
            }
        }

        temp_x = velo[0];
        velo[0] = velo[1] * (-1);
        velo[1] = temp_x;
    }
}