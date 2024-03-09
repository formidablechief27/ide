package com.example.ide;
import java.util.HashSet;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.autoconfigure.jdbc.DataSourceAutoConfiguration;
import org.springframework.scheduling.annotation.EnableAsync;

@EnableAsync
@SpringBootApplication(exclude = {DataSourceAutoConfiguration.class})
public class Server {
	
	static HashSet<Integer> set = new HashSet<>();
	
	public static void main(String args[]) {
		SpringApplication.run(Server.class, args);
	}
}

