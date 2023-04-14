package dao;

import model.User;
import util.CRUDUtils;
import util.jdbcUtils;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

public class LoginDao {
    public static List<User> ldao() throws Exception {
        String sql="select* from user";
        ResultSet  rs= CRUDUtils.query(sql);
        List<User> users=new ArrayList<>();
        while(rs.next()){
            User u=new User(rs.getString("username"), rs.getString("password"),null );
            users.add(u);
        }
        jdbcUtils.close(null,null,rs);
        return users;
    }
}
