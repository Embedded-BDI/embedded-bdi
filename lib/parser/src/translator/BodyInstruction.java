package translator;

import java.util.*;

public class BodyInstruction
{
  enum BodyType
  {
    ACTION,
    BELIEF,
    GOAL,
    INTERNAL_ACTION
  };

  private BodyType type;
  private String proposition;
  private EventOperatorType operator;
  private List<String> args = new ArrayList<String>();

  public BodyType getType()
  {
    return type;
  }

  public void setType(BodyType type)
  {
    this.type = type;
  }

  public String getProposition()
  {
    return proposition;
  }

  public void setProposition(String proposition)
  {
    this.proposition = proposition;
  }

  public EventOperatorType getOperator()
  {
    return operator;
  }

  public void setOperator(EventOperatorType operator)
  {
    this.operator = operator;
  }

  public void addArg(String a) {
    args.add(a);
  }

  public List<String> getArgs() {
    return args;
  }

  public String getArgsStr() {
    String r = "";
    String v = "";
    for (String a: args) {
        r = r +v + a;
        v = ", ";
    }
    return r;
  }

}
