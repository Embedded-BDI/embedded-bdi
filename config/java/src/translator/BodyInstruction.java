package translator;

public class BodyInstruction
{
  enum BodyType
  {
    ACTION,
    BELIEF,
    GOAL
  };

  private BodyType type;
  private String statement;
  private EventOperatorType operator;

  public BodyType getType()
  {
    return type;
  }

  public void setType(BodyType type)
  {
    this.type = type;
  }

  public String getStatement()
  {
    return statement;
  }

  public void setStatement(String statement)
  {
    this.statement = statement;
  }

  public EventOperatorType getOperator()
  {
    return operator;
  }

  public void setOperator(EventOperatorType operator)
  {
    this.operator = operator;
  }
}