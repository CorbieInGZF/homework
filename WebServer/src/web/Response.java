package web;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;

import static web.HttpServer.WEB_ROOT;

public class Response {
    private static final int BUFFER_SIZE = 1024;
    Request request;
    OutputStream output;

    public Response(OutputStream output) {
        this.output = output;
    }
/*
接收request
 */
    public void setRequest(Request request) {
        this.request = request;
    }
/*
服务器回应，发送资源到浏览器
 */
    public void sendStaticResource() throws IOException {
        byte[] bytes = new byte[BUFFER_SIZE];
        FileInputStream fis = null;
        if (WEB_ROOT != null && request.getUri() != null) {
            File file = new File(WEB_ROOT, request.getUri());
            String str = "";
            if (file.exists()) {
                fis = new FileInputStream(file);
                str = "HTTP/1.1 200 OK \r\n" +
                        "Content-Type: text/html\r\n" +
                        "\r\n";
                output.write(str.getBytes());
                int ch = fis.read(bytes);
                while (ch != -1) {
                    output.write(bytes, 0, ch);
                    ch = fis.read(bytes, 0, BUFFER_SIZE);
                }
            } else {
                //file not found
                str = "HTTP/1.1 404 File Not Found\r\n" +
                        "Content-Type:text/html\r\n" +
                        "Content-Length:23\r\n" +
                        "\r\n" +
                        "<h1>File Not Found</h1>";
                output.write(str.getBytes());
            }
        }
        output.close();//关闭
    }
}
