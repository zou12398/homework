package controller;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.lang.reflect.Method;

@WebServlet("/ser")
public class BaseServlet extends HttpServlet {
    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response) {
        try {
            ActionServlet l=new ActionServlet();
            response.setContentType("text/html;charset=utf-8");
            // 获取请求标识
            String methodName = request.getParameter("method");
            if(methodName==null){
                response.getWriter().write("<h1>未输入方法信息</h1>");
                return;
            }
            // 获取指定类的字节码对象
            Class<? extends BaseServlet> clazz = l.getClass();
            // 通过类的字节码对象获取方法的字节码对象
            Method method = clazz.getMethod(methodName, HttpServletRequest.class, HttpServletResponse.class);
            // 让方法执行
            method.invoke(l, request, response);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    @Override
    public void doPost(HttpServletRequest request, HttpServletResponse response) {
        doGet(request, response);
    }
}
