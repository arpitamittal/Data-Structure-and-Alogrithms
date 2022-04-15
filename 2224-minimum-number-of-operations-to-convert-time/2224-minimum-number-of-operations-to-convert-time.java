class Solution {
    public int convertTime(String current, String correct) {
        String[] arrOfCurrent = current.split(":");
        String[] arrOfCorrect = correct.split(":");
        int[] arr = new int[2];
        int[] carr = new int[2];

        arr[0] =  Integer.parseInt(arrOfCurrent[0])*60 + Integer.parseInt(arrOfCurrent[1]);
        carr[0] =  Integer.parseInt(arrOfCorrect[0])*60 + Integer.parseInt(arrOfCorrect[1]);

        int num = Math.abs(arr[0]-carr[0]);

        int ans = 0;
        while(num != 0){
            if(num>=60){
                ans = ans + num/60;
                num =  num % 60;
            }
            if(num>=15){
                ans = ans + num/15;
                num = num % 15;
            }
            else if(num>=5 && num<15){
                ans = ans + num/5;
                num = num % 5;
            }
            else if(num>=1 && num<5){
                ans = ans + num/1;
                num = num % 1;
            }
        }

        return ans;
    }
}