package web;

import java.io.InputStream;
/*
Request类实现一个HTPP请求,通过InputStream创建请求对象，再通过read方法读取HTTP请求。
 */
public class Request {
    private InputStream input;
    private String uri;

    public Request(InputStream input){
        this.input=input;
    }

    /*
    parse方法解析HTTP请求，需要再调用parseURI方法解析请求中的URI
     */
    public void parse(){
        //读取请求到request里
        StringBuffer request=new StringBuffer(2048);
        int i;
        byte[] buffer=new byte[2048];
        try {
            i=input.read(buffer);
        } catch (Exception e) {
            e.printStackTrace();
            i=-1;
        }
        for(int j=0;j<i;j++){
            request.append((char)buffer[j]);
        }
        System.out.print(request.toString());
        //调用parseURI
        uri=parseURI(request.toString());
    }
/*
解析URI的parseURI方法
 */
    public String parseURI(String requestString){
        int index1,index2;
        index1=requestString.indexOf(" ");
        if(index1!=-1){
            index2=requestString.indexOf('?',index1+1);
            if(index2==-1)index2=requestString.indexOf(' ',index1+1);
                return requestString.substring(index1+2,index2);
        }
        return null;
    }

    public String getUri(){
        return this.uri;
    }
}
