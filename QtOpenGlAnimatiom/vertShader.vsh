attribute highp vec3 a_position;
uniform highp mat4 u_mvp;
varying highp vec4 v_color;
void main(void)
{
   
    gl_Position = u_mvp * vec4(a_position,1);
    v_color = vec4(0,1,0,1);
}
