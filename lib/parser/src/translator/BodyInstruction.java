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
  private String proposition;
  private EventOperatorType operator;

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
}