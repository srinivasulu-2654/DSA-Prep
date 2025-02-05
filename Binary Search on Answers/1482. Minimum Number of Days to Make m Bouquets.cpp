bloomDay = [7,7,7,7,13,11,12,7], m = 2, k = 3

 Here the main thing we have to observe is we have to choose k adjacent flowers that makes m number of bouques 

So for the first thing we have to check on 7th day then [x,x,x,x,-,-,-,-,x] => x - is blosoom, '-' => is not blosoom  => here 3 adjacent flower can't make the m bouques
So for the first thing we have to check on 11th day then [x,x,x,x,-,x,-,x] => here also 3 adjacnet flowers can't make the m bouques
so and so if we take 12th day then [x,x,x,x,-,x,x,x] -> here we can make m bouques 

Bruete Force :

for(i = 0 -> n-1) 
{
   int cnt =0;
   int noOfBouques = 0;
   if(bloosom[i]<=day) {
     cnt++;
     if(cnt == k){
       noOfBouques++;
       cnt=0;
     }
   }
  else cnt = 0;
}
return noOfBouques >= m;

Here in the main question we have to run the loop from min element to maximum element

TC:O((max-min) * n)
