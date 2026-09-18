int better_than_average(int class_points[], int class_size, int your_points){
  
  int i, sum = 0, avg;
  
  for(i = 0; i < class_size; i++){
    sum += class_points[i];
  }
  
  avg = sum / class_size;
  
  if(your_points > avg){
    return 1;
  }
  else{
    return 0;
  }
}