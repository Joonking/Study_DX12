
//vs�ܰ迡�� ����� �͵��� �ش� �ڷ������� ����. 
struct VS_IN
{
    float3 pos : POSITION;
    float4 color : COLOR;
};

//vs�ܰ迡�� ���� ������� ���� �ڷ��� 
struct VS_OUT
{
    float4 pos : SV_Position;
    float4 color : COLOR;
};

//VS(Vertex Shader)�ܰ迡�� ���ؾ������� ����
//vs�ܰ�� ������ ��� ��ȭ������ ���ϴ� �ܰ�
VS_OUT VS_Main(VS_IN input)
{
    VS_OUT output = (VS_OUT) 0;

    //input���� ���� 3������ ��(float3)�� �״�� �־��ְ�, ������ ���� 1�� ä����
    //output.pos�� �־����.
    output.pos = float4(input.pos, 1.f);
    output.color = input.color;

    return output;
}

//PS(Pixel Shader) �ܰ迡�� �� �ؾ������� ����
//ps�ܰ�� ������ �����ִ� �ܰ���.
float4 PS_Main(VS_OUT input) : SV_Target
{
    return input.color;
}