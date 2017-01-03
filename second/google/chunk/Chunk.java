public class Chunk {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Chunk c=new Chunk();
        System.out.println(c.findPali("teammate"));
    }

    private int findPali(String str){
        int result=0;
        if(str.length()==0) return 0;
        int start=0,end=str.length()-1;
        while(start<end){
            if(str.charAt(start)==str.charAt(end)){ 
                result+=2;
                start++;end--;
            }else{
                int p=start,q=end;
                boolean find=false;
                while(q>start&&(end-q+1)*2<=str.length()){
                    if(str.charAt(q)==str.charAt(start)&&str.substring(start,start+end-q+1).equals(str.substring(q,end+1))){
                        result+=2;
                        start=start+end-q+2;
                        end=q-1;
                        find=true;
                        break;

                    }else{
                        q--;
                    }
                }
                if(!find){
                    result+=1;
                    return result;
                }
            }
        }
        return result;
    }
}
