package web;


import java.io.File;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class HttpServer {
    //WEB_ROOT为html文件路径
    public static  final String WEB_ROOT ="D:\\WebServer\\src\\web\\webroot";
    private static final String SHUTDOWN_COMMAND="/SHUTDOWN";

    public static void main(String[] args) {
        HttpServer server=new HttpServer();
        server.await();
    }
//持续监听
    public void await(){
        ServerSocket serverSocket=null;
        int port=8080;//定义端口号
        System.out.println("服务器开始监听请求！");
        try {
            serverSocket=new ServerSocket(8080,3,InetAddress.getByName("127.0.0.1"));
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(0);
        }
        while(true){
            Socket socket=null;
            InputStream input=null;
            OutputStream output=null;
            try {
                socket=serverSocket.accept();
                input=socket.getInputStream();
                output=socket.getOutputStream();
                //create Request object and parse
                Request request=new Request(input);
                request.parse();

                //create Response object
                Response response=new Response(output);
                response.setRequest(request);
                response.sendStaticResource();
            } catch (Exception e) {
                e.printStackTrace();
                continue;
            }
        }
    }
}
