public class MoveCell {
    static int up(int curPos){
       if(curPos/3==2)
           return -1;
       else
           return curPos+3;
    }
    static int down(int curPos){
        if(curPos/3==0)
            return -1;
        else
            return curPos-3;
    }
    static int left(int curPos){
        if((curPos+1)%3==0)
            return -1;
        else
            return curPos+1;

    }
    static int right(int curPos){

        if(curPos%3==0)
            return -1;
        else
            return curPos-1;
    }

}
