package service;

import dao.LoginDao;
import model.User;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.Writer;
import java.util.List;
import java.util.Objects;

public class Login {

    public Login() {
    }

    public void log(HttpServletRequest req, HttpServletResponse resp) throws Exception {
        String username=req.getParameter("username");
        String password=req.getParameter("password");
        List<User> users=LoginDao.ldao();
        resp.setContentType("text/html;charset=utf-8");
        Writer writer=resp.getWriter();

        if(username == null | password == null| Objects.equals(username, "") | Objects.equals(password, "")){
            writer.write("<h1>未输入信息</h1>");
            return;
        }
        for (User u : users) {
            if (Objects.equals(u.getUsername(), username) & u.getPassword().equals(password)) {
                writer.write("<h1>登录成功</h1>");
                return;
            }

        }
            writer.write("<h1>登录失败</h1>");
    }
}
