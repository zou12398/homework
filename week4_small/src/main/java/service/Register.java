package service;

import dao.LoginDao;
import dao.RegisterDao;
import model.User;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.PrintWriter;
import java.util.List;
import java.util.Objects;

public class Register {
    public Register() {
    }

    public void reg(HttpServletRequest req, HttpServletResponse resp) throws Exception {
        resp.setContentType("text/html;charset=utf-8");
        String username=req.getParameter("username");
        String password=req.getParameter("password");
        PrintWriter writer=resp.getWriter();
        if(Objects.equals(username, "") | Objects.equals(password, "")){
            writer.write("<h1>未输入信息</h1>");
            return;
        }
        List<User> users= LoginDao.ldao();
        for(User u:users){
            if (Objects.equals(u.getUsername(), username) ) {
                writer.write("<h1>用户已注册</h1>");
                return;
            }
        }
        RegisterDao.regi(username,password);
        writer.write("<h1>注册成功</h1>");
    }
}
