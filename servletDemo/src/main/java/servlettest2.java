import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.*;
import java.util.Map;
import java.util.Objects;


@WebServlet("/demo2")
public class servlettest2 extends HttpServlet {

    static ResultSet rs;
    static Connection conn;
    static String sql1="select* from user";
    static Statement state;


    static {
        {
            try {
                Class.forName("com.mysql.cj.jdbc.Driver");
                conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/test", "root", "Zou1166881979");
                state = conn.createStatement();

            } catch (SQLException | ClassNotFoundException e) {
                throw new RuntimeException(e);
            }
        }
    }


    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        resp.setContentType("text/html;charset=utf-8");
        Map<String,String[]> map=req.getParameterMap();
        String username1=req.getParameter("username");
        String password1=req.getParameter("password");
        PrintWriter writer=resp.getWriter();
        System.out.println(username1);
        if(Objects.equals(username1, "") | Objects.equals(password1, "")){
            writer.write("<h1>未输入信息</h1>");
            return;
        }
        String name=null;
        try {
            rs=state.executeQuery(sql1);
            while (rs.next()){
                name= rs.getString("username");
                if(name.equals(username1)){
                    break;
                }else {
                    name=null;
                }
            }
            if(name!=null) {
                writer.write("<h1>用户已存在</h1>");
            }else{
                String sql2="insert into user(username,password) values('"+username1+"','"+password1+"')";
                state.executeUpdate(sql2);
                writer.write("<h1>注册成功</h1>");
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        this.doGet(req, resp);
    }
}
