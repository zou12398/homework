package controller;

import service.Login;
import service.Register;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
@WebServlet("/ActionServlet/*")
public class ActionServlet extends BaseServlet {

    public void lo(HttpServletRequest req, HttpServletResponse resp) {

        Login l=new Login();
        try {
            l.log(req,resp);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public void regis(HttpServletRequest req,HttpServletResponse resp){
        Register r=new Register();
        try {
            r.reg(req, resp);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
