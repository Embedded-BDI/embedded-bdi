package translator;

import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;

import jason.asSemantics.Agent;
import jason.asSyntax.Literal;
import jason.asSyntax.Plan;
import jason.asSyntax.PlanBody;
import jason.asSyntax.PlanBody.BodyType;
import jason.asSyntax.parser.as2j;
import jason.util.Config;

public class As2Json {
	public static void main(String[] args) {
		new As2Json().run(args[0]);
	}

	void run(String file) {
		try {
			Config.get().setProperty(Config.START_WEB_MI,"false");

			as2j parser = new as2j(new FileInputStream(file));
			Agent ag = new Agent();
			ag.initAg();
			parser.agent(ag); // parse the file and place all data in agent ag
			
			System.out.println("BB: "+ag.getInitialBels());
			System.out.println("Goals"+ ag.getInitialGoals());
			System.out.println("PL: "+ag.getPL());
			
			// write down the translation
			BufferedWriter out = new BufferedWriter(new FileWriter(file+".out"));
			
			for (Literal l : ag.getInitialBels()) {
				out.append("Bel: "+l.toString()+"\n");
			}
			
			for (Literal l : ag.getInitialGoals()) {
				out.append("\nGoals: "+l.toString()+"");
			}

			for (Plan p: ag.getPL()) {
				out.append("\n\nPlan trigger: "+p.getTrigger());
				out.append("\n     context: "+p.getContext());
				out.append("\n     body: "+p.getBody());
			}
			out.append("\n");
			out.close();
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
