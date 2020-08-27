package translator;

import java.util.ArrayList;

public class PlanSkeleton
{
  private EventOperatorType operator;
  private String statement;
  private ArrayList<String> context;
  private ArrayList<BodyInstruction> body_instruction;

  public PlanSkeleton()
  {
    this.context = new ArrayList<String>();
    body_instruction = new ArrayList<BodyInstruction>();
  }  

  public EventOperatorType getOperator()
  {
    return this.operator;
  }

  public void setOperator(EventOperatorType operator)
  {
    this.operator = operator;
  }

  public String getStatement()
  {
    return this.statement;
  }

  public void setStatement(String statement)
  {
    this.statement = statement;
  }

  public ArrayList<String> getContext() 
  {
    return this.context;
  }

  public void addContext(String context)
  {
    this.context.add(context);
  }

  public void setContext(ArrayList<String> context)
  {
    this.context = context;
  }

  public ArrayList<BodyInstruction> getBodyInstruction()
  {
    return this.body_instruction;
  }

  public void addBodyInstruction (BodyInstruction instruction)
  {
    this.body_instruction.add(instruction);
  }

  public void setBodyInstruction(ArrayList<BodyInstruction> inst)
  {
    this.body_instruction = inst;
  }

  public int getBodySize()
  {
    return this.body_instruction.size();
  }
}